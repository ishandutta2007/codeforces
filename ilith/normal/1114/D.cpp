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
const int N=5010;
int n,c[N],dp[N][N];
signed main(){
	read(n);
	for(rgi i=1;i<=n;++i)read(c[i]);
	n=unique(c+1,c+n+1)-c-1;
	for(rgi i=1;i<n;++i)dp[i][i+1]=(c[i]!=c[i+1]);
	for(rgi len=3;len<=n;++len){
		for(rgi i=1;i+len-1<=n;++i){
			int j=i+len-1;
			dp[i][j]=min(dp[i][j-1],dp[i+1][j]);
			if(c[i]==c[j])dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
			++dp[i][j];
		}
	}
	write(dp[1][n]);
	return 0;
}