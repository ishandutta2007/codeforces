#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

int n,k,L,x[2001],y[2001],c[2001],origx[2010],origy[2010],limx,limy;
std::vector<std::pair<int,int> >vec[2001];
std::multiset<int>set[2001];
int mn[100001],sum[100001],ans[100001],lazy[100001];
const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
void pushup(int root){
	sum[root]=add(sum[root<<1],sum[root<<1|1]);
	ans[root]=add(ans[root<<1],ans[root<<1|1]);
	mn[root]=std::min(mn[root<<1],mn[root<<1|1]);
}
void build(int root,int l,int r){
	lazy[root]=-1;
	if(l==r){
		sum[root]=origy[l]-origy[l-1];
		ans[root]=mul(L-origy[l],sum[root]);
		mn[root]=l;
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	pushup(root);
}
void pushdown(int x,int y){
	lazy[x]=y;
	mn[x]=y;
	ans[x]=mul(sum[x],L-origy[y]);
}
void spread(int x){
	if(~lazy[x]){
		pushdown(x<<1,lazy[x]);
		pushdown(x<<1|1,lazy[x]);
		lazy[x]=-1;
	}
}
int find(int root,int l,int r,int x){
	spread(root);
	if(l==r&&mn[root]<x)return l;
	if(l==r&&mn[root]>=x)return -1;
	if(mn[root<<1|1]<x)return find(root<<1|1,((l+r)>>1)+1,r,x);
	else return find(root<<1,l,(l+r)>>1,x);
}
void upd(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root,x);
		return;
	}
	spread(root);
	upd(root<<1,l,(l+r)>>1,el,er,x);
	upd(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	pushup(root);
}
void del(int l,int r){
//	printf("del %d %d\n",l,r);
	int x=find(1,1,limy,r);
//	printf("%d\n",x);
	if(x<l)return;
	upd(1,1,limy,l,x,r);
}
int main(){
	scanf("%d%d%d",&n,&k,&L);
	for(int i=1;i<=n;i++)scanf("%d%d%d",x+i,y+i,c+i),origx[i]=x[i],origy[i]=y[i];
	std::sort(origx+1,origx+n+1);
	limx=std::unique(origx+1,origx+n+1)-origx-1;
	for(int i=1;i<=n;i++)x[i]=std::lower_bound(origx+1,origx+limx+1,x[i])-origx;
	std::sort(origy+1,origy+n+1);
	limy=std::unique(origy+1,origy+n+1)-origy-1;
	for(int i=1;i<=n;i++)y[i]=std::lower_bound(origy+1,origy+limy+1,y[i])-origy;
	origx[limx+1]=origy[limy+1]=L;
	origx[0]=origy[0]=-1;
	for(int i=1;i<=n;i++)vec[x[i]].push_back(std::make_pair(y[i],c[i]));
	int ans=0;
//	for(int i=0;i<=limx+1;i++)printf("%d ",origx[i]);putchar('\n');
	for(int i=limx;i;i--){
		for(int j=1;j<=k;j++)set[j].clear(),set[j].insert(limy+1),set[j].insert(0);
		for(int j=i;j<=limx;j++)
			for(int k=0;k<vec[j].size();k++)
				set[vec[j][k].second].insert(vec[j][k].first);
//		puts("build");
		build(1,1,limy);
		for(int j=1;j<=k;j++)
			for(std::multiset<int>::iterator it=set[j].begin();it!=set[j].end();++it){
//				printf("%d ",*it);
				if(*it==limy+1)break;
				auto now=it;
				++now;
//				printf("neighbor %d %d\n",*it,*now);
				if(*it<*now)del(*it+1,*now);
			}
		for(int j=limx;j>=i;j--){
			ans=add(ans,mul(mul(origx[i]-origx[i-1],origx[j+1]-origx[j]),::ans[1]));
//			printf("*%d\n",::ans[1]);
			for(int k=0;k<vec[j].size();k++){
				int y=vec[j][k].first,c=vec[j][k].second;
				auto now=set[c].find(y);
				int l,r;
				auto tem=now;
				l=*--tem+1;
				tem=now;
				r=*++tem;
				del(l,r);
				set[c].erase(now);
			}
		}
//		printf("%d\n",ans);
	}
	printf("%d\n",ans);
}