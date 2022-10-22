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
const int N=200010;
int T,n,u,v,c[N],fa[N],ans;
vector<int>a[N];
void dfs(int x,int f){
	c[x]=0,fa[x]=f;
	for(rgi to:a[x]){
		if(to!=f)dfs(to,x),c[x]+=!c[to];
	}
}
signed main(){
	read(T);
	while(T--){
		read(n);
		for(rgi i=1;i<=n;++i)a[i].clear();
		for(rgi i=1;i<n;++i){
			read(u,v),a[u].pbk(v),a[v].pbk(u);
		}
		dfs(1,0),ans=c[1];
		for(rgi i=2,w=ans;i<=n;++i){
			if(c[i]){
				if(w)ans+=c[i]-1;
				else w=1,ans+=c[i];
			}
		}
		write(ans,'\n');
	}
	return 0;
}