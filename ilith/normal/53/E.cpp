#include<bits/stdc++.h>
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
const int N=15,S=(1<<10)+10;
#define get(x,d) (x>>(d-1)&1)
#define cal(d) (1<<d-1)
#define cnt(x) __builtin_popcount(x)
int n,m,k,u,v,ans;
int dp[S][S],a[N][N];
signed main(){
	read(n,m,k);
	for(rgi i=1;i<=m;++i)read(u,v),a[u][v]=a[v][u]=1;
	for(rgi i=1;i<(1<<n);i<<=1)dp[i][i]=1;
	for(rgi i=1;i<(1<<n);++i){
		for(rgi j=i;j;--j&=i){
			for(rgi x=1;x<=n;++x)if(get(i,x)){
				for(rgi y=1;y<=n;++y)if(a[x][y]&&!get(i,y)){
					int s=(j|cal(y));
					if(cnt(i)>1&&get(s,x))s^=cal(x);
					if(!(s>>y))dp[i|cal(y)][s]+=dp[i][j];
				}
			}
		}
	}
	for(rgi i=1;i<(1<<n);++i){
		if(cnt(i)==k)ans+=dp[(1<<n)-1][i];
	}
	write(ans);
	return 0;
}