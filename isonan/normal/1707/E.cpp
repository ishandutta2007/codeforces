#include <cstdio>
#include <algorithm>
#include <vector>

int Log[100001];
int n,q,a[100001],L[100001],R[100001];
struct ST{
	int st[100001][21];
	void init(){
		for(int j=1;(1<<j)<=n;++j)
			for(int i=1;i+(1<<j)-1<=n;++i)
				st[i][j]=std::min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	int query(int l,int r){
		if(l>r)return 0x7f7f7f7f;
		int k=Log[r-l+1];
		return std::min(st[l][k],st[r-(1<<k)+1][k]);
	}
}mn[21],mx[21],amn;
int f[100001];
int dis[100001];
int Q[100001],h,t;
std::vector<int>vec[1000001];
void add(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		vec[root].push_back(x);
		// printf("add %d %d\n",root,x);
		return;
	}
	add(root<<1,l,(l+r)>>1,el,er,x);
	add(root<<1|1,((l+r)>>1)+1,r,el,er,x);
}
void upd(int root,int l,int r,int e,int d){
	for(int i=0;i<vec[root].size();++i){
		int u=vec[root][i];
		if(dis[vec[root][i]]>d){
			dis[u]=d;
			Q[++t]=u;
		}
	}
	vec[root].clear();
	if(l==r)return;
	if((l+r)>>1>=e)upd(root<<1,l,(l+r)>>1,e,d);
	else upd(root<<1|1,((l+r)>>1)+1,r,e,d);
}
int ans[100001];
bool vis[100001];
void upd2(int root,int l,int r,int e,int d){
	for(int i=0;i<vec[root].size();++i){
		int u=vec[root][i];
		if(ans[vec[root][i]]==-1){
			ans[u]=d;
			Q[++t]=u;
		}
	}
	vec[root].clear();
	if(l==r)return;
	if((l+r)>>1>=e)upd2(root<<1,l,(l+r)>>1,e,d);
	else upd2(root<<1|1,((l+r)>>1)+1,r,e,d);
}
int getans(int l,int r,int st){
	for(int i=20;~i;--i)
		if(st>=(1<<i)){
			st-=1<<i;
			int ol=l,Or=r;
			l=mn[i].query(ol,Or);
			r=-mx[i].query(ol,Or);
		}
	return r;
}
int g[100001];
void upd3(int root,int l,int r,int e,int d){
	// printf("%d %d %d\n",root,l,r);
	for(int i=0;i<vec[root].size();++i){
		int u=vec[root][i];
		// printf("%d\n",u);
		if(f[vec[root][i]]==-1){
			f[u]=d+g[u];
			Q[++t]=u;
		}
	}
	vec[root].clear();
	if(l==r)return;
	if((l+r)>>1>=e)upd3(root<<1,l,(l+r)>>1,e,d);
	else upd3(root<<1|1,((l+r)>>1)+1,r,e,d);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=2;i<=n;++i)Log[i]=Log[i>>1]+1;
	for(int i=1;i<n;++i)L[i]=std::min(a[i],a[i+1]),R[i]=std::max(a[i],a[i+1])-1;
	for(int i=0;(1<<i)<=n;++i){
		for(int j=1;j<n;++j){
			if(i==0){
				mn[i].st[j][0]=L[j];
				mx[i].st[j][0]=-(R[j]);
			}
			else{
				int l=mn[i-1].query(j,j);
				int r=-mx[i-1].query(j,j);
				mn[i].st[j][0]=mn[i-1].query(l,r);
				mx[i].st[j][0]=mx[i-1].query(l,r);
				// printf("%d %d %d %d %d %d\n",j,i,l,r,mn[i-1].query(l,r),-mx[i-1].query(l,r));
			}
		}
		mn[i].init();
		mx[i].init();
	}
	for(int i=2;i<n;++i)add(1,1,n,L[i],R[i],i);
	for(int i=1;i<=n;++i)dis[i]=0x7f7f7f7f;
	Q[++t]=1;
	dis[1]=0;
	while(h<t){
		++h;
		upd(1,1,n,Q[h],dis[Q[h]]+1);
	}
	for(int i=1;i<n;++i)amn.st[i][0]=dis[i];
	amn.init();
	for(int i=1;i<=1000000;++i)vec[i].clear();
	for(int i=1;i<=n;++i)add(1,1,n,a[i],a[i],i);
	h=t=0;
	for(int i=1;i<=n;++i)ans[i]=-1;
	Q[++t]=1;
	ans[1]=0;
	while(h<t){
		++h;
		upd2(1,1,n,Q[h],ans[Q[h]]+1);
	}
	// for(int i=1;i<=n;++i)printf("%d ",ans[i]);putchar('\n');
	for(int i=1;i<=1000000;++i)vec[i].clear();
	for(int i=1;i<n-1;++i){
		int L=mn[0].query(1,i),R=-mx[0].query(1,i);
		int mn=amn.query(L,R);
		if(mn==0x7f7f7f7f)f[i]=-1;
		else{
			++mn;
			int now=getans(1,i,mn);
			// printf("%d %d %d\n",i,now,mn);
			f[i]=-1;
			g[i]=mn;
			add(1,1,n,now,now,i);
		}
	}
	h=t=0;
	Q[++t]=n-1;
	f[n-1]=0;
	while(h<t){
		++h;
		// printf("%d\n",Q[h]);
		upd3(1,1,n,Q[h],f[Q[h]]);
	}
	// for(int i=1;i<n;++i)printf("%d ",f[i]);putchar('\n');
	for(int i=1,l,r;i<=q;++i){
		scanf("%d%d",&l,&r);
		if(l==r){
			if(n==1)puts("0");
			else puts("-1");
		}
		else{
			int mn=amn.query(l,r-1);
			// printf("%d\n",mn);
			if(mn==0x7f7f7f7f)puts("-1");
			else{
				int now=getans(l,r-1,mn);
				// printf("%d\n",now);
				if(f[now]==-1)puts("-1");
				else printf("%d\n",mn+f[now]);
			}
		}
	}
}