#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

int n,k,a[300001],b[300001],orig[600010],lim;
long long se[3000001],lazy[3000001],siz[3000001];
void pushup(int x){se[x]=se[x<<1]+se[x<<1|1];}
void pushdown(int x,long long y){
//	printf("pushdown %d %d\n",x,y);
	se[x]+=siz[x]*y;
	lazy[x]+=y;
}
void spread(int x){
	if(lazy[x]){
		pushdown(x<<1,lazy[x]);
		pushdown(x<<1|1,lazy[x]);
		lazy[x]=0;
	}
}
void build(int root,int l,int r){
	se[root]=lazy[root]=0;
	if(l==r){
		siz[root]=1;
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	pushup(root);
	siz[root]=siz[root<<1]+siz[root<<1|1];
}
void update(int root,int l,int r,int e,int x){
//	if(root==1)printf("update %d %d\n",e,x);
	spread(root);
	if(e<l)return;
	if(e>=r)return pushdown(root,x);
	update(root<<1,l,(l+r)>>1,e,x);
	update(root<<1|1,((l+r)>>1)+1,r,e,x);
	pushup(root);
}
long long query(int root,int l,int r,int el,int er){
	spread(root);
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se[root];
	return query(root<<1,l,(l+r)>>1,el,er)+query(root<<1|1,((l+r)>>1)+1,r,el,er);
}
std::vector<std::pair<int,int> >vec[300001];
int time[3000001];
void upd(int root,int l,int r,int el,int er,int t){
//	printf("upd %d %d %d %d %d %d %d\n",root,l,r,el,er,t,time[root]);
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		if(~time[root]){
			if(vec[t].empty()||vec[t].back().first!=time[root])vec[t].push_back(std::make_pair(time[root],0));
			vec[t].back().second+=orig[r+1]-orig[l];
		}
		else upd(root<<1,l,(l+r)>>1,el,er,t),upd(root<<1|1,((l+r)>>1)+1,r,el,er,t);
		time[root]=t;
		return;
	}
	if(~time[root])time[root<<1]=time[root<<1|1]=time[root];
	upd(root<<1,l,(l+r)>>1,el,er,t);
	upd(root<<1|1,((l+r)>>1)+1,r,el,er,t);
	time[root]=(time[root<<1]==time[root<<1|1])?time[root<<1]:-1;
}
long long c[300010];
long long judge(int u){
	long long tot=0,sum=0;
	memset(c,0,sizeof c);
	for(int i=1,pre=0;i<=n;i++){
		for(int j=0;j<vec[i].size();j++){
			if(vec[i][j].first>=pre)c[vec[i][j].first]-=vec[i][j].second,sum-=vec[i][j].second;
//			printf("%d %d %d\n",i,it->first,it->second);
		}
		c[i]+=orig[b[i]+1]-orig[a[i]],sum+=orig[b[i]+1]-orig[a[i]];
		while(sum-c[pre]>=u)sum-=c[pre++];
		tot+=pre;
		if(tot+1ll*(n-i)*pre>=k)return tot+1ll*(n-i)*pre;
	}
	return tot;
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)orig[(i<<1)-1]=a[i]=read(),orig[i<<1]=b[i]=read();
	std::sort(orig+1,orig+(n<<1)+1);
	lim=std::unique(orig+1,orig+(n<<1)+1)-orig-1;
	for(int i=1;i<=n;i++)
		a[i]=std::lower_bound(orig+1,orig+lim+1,a[i])-orig,
		b[i]=std::lower_bound(orig+1,orig+lim+1,b[i])-orig-1;
	int l=1,r=1000000000,mid,ans;
	for(int i=1;i<=n;i++)upd(1,1,lim,a[i],b[i],i);
	while(l<=r){
		mid=(l+r)>>1;
		long long t=judge(mid);
		if(t>=k)ans=mid,l=mid+1;
		else r=mid-1;
	}
	long long fin=0,cnt=0;
	build(1,1,n);
	for(int i=1,pre=0;i<=n;i++){
		for(int j=0;j<vec[i].size();j++){
			update(1,1,n,vec[i][j].first,-vec[i][j].second);
//			printf("%d %d %d\n",i,it->first,it->second);
		}
		update(1,1,n,i,orig[b[i]+1]-orig[a[i]]);
		while(query(1,1,n,pre+1,pre+1)>=ans)++pre;
		fin+=query(1,1,n,1,pre);
		cnt+=pre;
	}
	printf("%lld\n",fin+1ll*(k-cnt)*ans);
}