#include<bits/stdc++.h>
#define int ll
#define rgi register int
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
const int N=100010;
int t,n;
vector<int>a[N];
int dp[N][2],l[N],r[N];
int calc(int x,int y){return abs(x-y);}
void dfs(int x,int f){
	for(rgi to:a[x]){
		if(to==f)continue;
		dfs(to,x);
		dp[x][0]+=max(calc(l[x],r[to])+dp[to][1],calc(l[x],l[to])+dp[to][0]);
		dp[x][1]+=max(calc(r[x],r[to])+dp[to][1],calc(r[x],l[to])+dp[to][0]);
	}
}
signed main(){
	read(t);
	while(t--){
		read(n);
		for(rgi i=1;i<=n;++i)a[i].clear(),read(l[i],r[i]),dp[i][0]=dp[i][1]=0;
		for(rgi i=1;i<n;++i){
			int u,v;read(u,v);
			a[u].push_back(v),a[v].push_back(u);
		}
		dfs(1,0),write(max(dp[1][0],dp[1][1]),'\n');
	}
	return 0;
}