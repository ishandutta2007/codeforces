#include<bits/stdc++.h>
#define rgi register int
#define pii pair<int,int>
#define fi first
#define se second
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=20010;
int n,m,d[N],F[N],u[N],v[N],ans[N],dp[N],fa[N],q[N],to[N*2],da[N*2];
char up[N],s[N];
int x,y;
vector<pii>vec[N];
int main(){
	read(n,m);
	for(rgi i=1;i<n;++i){
		scanf("%d %d %c",&u[i],&v[i],&s[i]);
		++d[u[i]],++d[v[i]];
	}
	for(rgi i=1;i<=n;++i)d[i+1]+=d[i];
	for(rgi i=1;i<n;++i){
		--d[u[i]],to[d[u[i]]]=v[i],da[d[u[i]]]=s[i];
		--d[v[i]],to[d[v[i]]]=u[i],da[d[v[i]]]=s[i];
	}
	for(rgi i=1;i<=m;++i)read(x,y),vec[x].emplace_back(y,i);
	for(rgi i=1;i<=n;++i)if(!vec[i].empty()){
		int t=-1,w=-1;q[++w]=i;
		fa[i]=up[i]=dp[i]=0;F[i]=0;
		for(;t<w;){
			int x=q[++t];
			for(rgi i=d[x],y;i<d[x+1];++i){
				if((y=to[i])!=fa[x]){
					fa[y]=x,up[y]=da[i],dp[y]=dp[x]+1,q[++w]=y;
				}
			}
		}
		for(auto j:vec[i]){
			int v=j.fi,L=dp[v],res=0;
			s[L+1]=0;
			for(;v!=i;v=fa[v])s[dp[v]]=up[v];
			for(rgi k=1;k<n;++k){
				int x=q[k];
				if(F[fa[x]])F[x]=F[fa[x]];
				else F[x]=(up[x]<s[dp[x]])-(up[x]>s[dp[x]]);
				res+=(F[x]==1||(F[x]==0&&dp[x]<L));
			}
			ans[j.se]=res;
		}
	}
	for(rgi i=1;i<=m;++i)write(ans[i],'\n');
	return 0;
}