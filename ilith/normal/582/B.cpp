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
const int N=110,K=110;
int n,t;
ll a[N*(K+1)],dp[N*(K+1)],res;
signed main(){
	read(n,t);
	for(rgi i=1;i<=n;++i)read(a[i]);
	for(rgi i=n+1;i<=K*n;++i)a[i]=a[i-n];
	for(rgi i=1;i<=K*n;++i){
		dp[i]=1;
		for(rgi j=max(i-n,1);j<i;++j){
			if(a[j]<=a[i])dp[i]=max(dp[i],dp[j]+1);
		}
	}
	if(t<=K){
		for(rgi i=1;i<=n*t;++i)res=max(res,dp[i]);
		write(res);
		return 0;
	}
	else{
		for(rgi i=(K-1)*n+1;i<=K*n;++i){
			res=max(res,dp[i]+(dp[i]-dp[i-n])*(t-K));
		}
		write(res);
	}
	return 0;
}
/*
31 3767
16 192 152 78 224 202 186 52 118 19 13 38 199 196 35 295 100 64 205 37 166 124 169 214 66 243 134 192 253 270 92

*/