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
const int N=6000010;
ll n,mod,dp[N],f[N];
signed main(){
	read(n,mod);
	for(rgi i=1;i<=n;i++){
		f[i]=(~-i?(dp[i]+=dp[i-1])%=mod:1),(dp[i+1]+=f[i])%=mod;
		for(rgi j=2;j<=n/i;++j){
			if(i*j<=n)(dp[i*j]+=f[i])%=mod;
			if(i*j+j<=n)(dp[i*j+j]-=f[i])%=mod;
		}
	}
	write((dp[n]+mod)%mod);
	return 0;
}