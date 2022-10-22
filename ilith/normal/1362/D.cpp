#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
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
const int N=500010;
int t,n,m,a[N],b[N],p[N],vis[N];
vector<int>g[N]; 
signed main(){
	read(n,m);
	for(rgi i=1;i<=m;++i){
		int u,v;
		read(u,v);
		g[u].pbk(v),g[v].pbk(u);
	}
	for(rgi i=1;i<=n;++i)p[i]=i,read(a[i]);
	sort(p+1,p+n+1,[&](int x,int y){return a[x]<a[y];});
	for(rgi i=1;i<=n;++i){
		int x=p[i];
		for(rgi to:g[x]){
			if(b[to])vis[b[to]]=1;
		}
		for(rgi i=1;!b[x];++i){
			if(!vis[i])b[x]=i;
		}
		for(rgi to:g[x]){
			if(b[to])vis[b[to]]=0;
		}
	}
	for(rgi i=1;i<=n;++i){
		if(a[i]!=b[i]){
			puts("-1");
			goto tag;
		}
	}
	for(rgi i=1;i<=n;++i)write(p[i],' ');
	tag:;
	return 0;
}