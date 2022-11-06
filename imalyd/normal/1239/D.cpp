#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace io{
	const int l=1<<20;
	char buf[l],*s,*t;
	inline char gc(){
		if(s==t){
			t=(s=buf)+fread(buf,1,l,stdin);
			return s==t?EOF:*s++;
		}
		return *s++;
	}
	char c;
	template<class IT>inline void gi(IT &x){
		x=0;c=gc();while(c<'0'||c>'9')c=gc();
		while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=gc();}
	}
};
using io::gi;
template<class IT>inline void _int(      IT &a,      IT &b  ){if(a>b)swap(a,b);}
template<class IT>inline void cmin(      IT &a,const IT &b=0){if(a>b)a=b;}
template<class IT>inline void cmax(      IT &a,const IT &b=0){if(a<b)a=b;}
template<class IT>inline IT   _min(const IT &a,const IT &b=0){return a>b? b:a;}
template<class IT>inline IT   _max(const IT &a,const IT &b=0){return a<b? b:a;}
template<class IT>inline IT   _abs(const IT &a              ){return a<0?-a:a;}

const int N=1000005;
vector<int>e[N];
int ans[N],st[N],in[N],low[N],dfn[N],tot,cnt,tp;
void dfs(int v){
//	printf("dfs v=%d\n",v);
	in[v]=1;st[++tp]=v;low[v]=dfn[v]=++cnt;
	int s=e[v].size(),i,u;
	for(i=0;i<s;++i){
		u=e[v][i];//printf("dfs u=%d\n",u);
		if(!dfn[u]){dfs(u);cmin(low[v],low[u]);}
		else if(in[u])cmin(low[v],dfn[u]);
	}
	if(low[v]==dfn[v]){
		++tot;
		do{
			u=st[tp--];
			in[u]=0;
			ans[u]=tot;
		}while(u!=v);
	}
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int t,n,m,v,u,i,sz;
	scanf("%d",&t);
	while(t--){
		tot=sz=0;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i)e[i].clear();
		while(m--){scanf("%d%d",&v,&u);e[v].push_back(u);}
		for(i=1;i<=n;++i)dfn[i]=0;
		for(i=1;i<=n;++i)if(!dfn[i])dfs(i);
		if(tot==1){puts("No");continue;}
//		for(i=1;i<=n;++i)printf("%d ",ans[i]);printf("\n");
		for(i=1;i<=n;++i)if(ans[i]==1)++sz;
		printf("Yes\n%d %d\n",sz,n-sz);
		for(i=1;i<=n;++i)if(ans[i]==1)printf("%d ",i);printf("\n");
		for(i=1;i<=n;++i)if(ans[i]!=1)printf("%d ",i);printf("\n");
	}
	return 0;
}