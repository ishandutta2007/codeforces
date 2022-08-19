#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>

int n,a[200001],cnt[200001],pre[200001],last[200001],nxt[200010];
int f[200001];
std::vector<int>vec[200001];
struct info{
	int m1,m2,v1,v2;
	void add(int m,int v){
		if(v1<v){
			v2=v1,m2=m1;
			v1=v,m1=m;
		}
		else if(v2<v){
			v2=v,m2=m;
		}
	}
};
int se[2000001],lazy[2000001];
void pushdown(int x,int y){
	se[x]+=y;
	lazy[x]+=y;
}
void spread(int x){
	if(lazy[x]){
		pushdown(x<<1,lazy[x]);
		pushdown(x<<1|1,lazy[x]);
		lazy[x]=0;
	}
}
int sum[200001];
void build(int root,int l,int r){
	lazy[root]=0;
	if(l==r){
		se[root]=-sum[l-1];
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=std::min(se[root<<1],se[root<<1|1]);
}
void update(int root,int l,int r,int el,int er,int x){
//	if(root==1)printf("update %d %d %d\n",el,er,x);
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root,x);
		return;
	}
	spread(root);
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	se[root]=std::min(se[root<<1],se[root<<1|1]);
}
int get(int root,int l,int r,int s){
//	printf("get %d %d %d\n",l,r,se[root]);
	if(se[root]+s>0)return n+1;
	spread(root);
	if(l==r)return l;
	if(se[root<<1]+s<=0)return get(root<<1,l,(l+r)>>1,s);
	else return get(root<<1|1,((l+r)>>1)+1,r,s);
}
int query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return 0x7f7f7f7f;
	if(el<=l&&er>=r){
		return se[root];
	}
	spread(root);
	return std::min(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		++cnt[a[i]];
		vec[a[i]].push_back(i);
	}
	std::set<std::pair<int,int> >set;
	for(int i=1;i<=n;i++)set.insert(std::make_pair(cnt[i],i));
	set.insert(std::make_pair(0,0));
	if(set.rbegin()->first==(--set.rbegin())->first){
		printf("%d",n);
		return 0;
	}
	int ans=0;
	int mx=set.rbegin()->second;
	int r=n-1;
	for(;r;){
		set.erase(std::make_pair(cnt[a[r+1]],a[r+1]));
		--cnt[a[r+1]];
		set.insert(std::make_pair(cnt[a[r+1]],a[r+1]));
		if((set.rbegin()->first)==(--set.rbegin())->first){
			ans=std::max(ans,r);
			break;
		}
		else --r;
	}
	nxt[n+1]=n+1;
	for(int i=n;i;i--)nxt[i]=(a[i]==mx)?i:nxt[i+1];
	for(int i=1;i<=n;i++)f[i]=n+1;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(a[i]==mx);
	build(1,1,n);
	int cnt=0;
	for(int j=1;j<=n;j++){
		if(j==mx)continue;
		vec[j].push_back(n+1);
		for(int k=0;k<vec[j].size()-1;k++){
			update(1,1,n,1,vec[j][k],-1);
			int now=vec[j][k],nx=std::min(vec[j][k+1],nxt[now+1])-1;
			ans=std::max(ans,nx-get(1,1,n,sum[nx])+1);
			while(query(1,1,n,1,now)+sum[now]<0&&now<vec[j][k+1]){
				++cnt;
				if(cnt>(n<<2)){
					return 2;
				}
				now=nx+1;
				nx=std::min(vec[j][k+1],nxt[now+1])-1;
				ans=std::max(ans,nx-get(1,1,n,sum[nx])+1);
			}
		}
		for(int k=0;k<vec[j].size()-1;k++)
			update(1,1,n,1,vec[j][k],1); 
	}
	printf("%d\n",ans);
}