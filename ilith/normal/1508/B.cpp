#include<bits/stdc++.h>
#define rgi register int
#define mid (l+r>>1)
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
ll n,t,k,a[N];
inline ll qpow(ll a,ll b){
	if(b<0)return 0;
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a;
		b>>=1,a=a*a;
	}
	return ans;
}
ll check(ll i,ll x){
	if(x==i)return 0;
	if(log2(k)+1<n-x)return k+1;
	ll tmp=qpow(2,n-x);
	if(log2(k+tmp)+1<n-i)return k+1;
	return qpow(2,n-i)-tmp;
}
signed main(){
	read(t);
	while(t--){
		read(n,k),memset(a,0,sizeof a);
		if((n==1&&k==2)||(k>2&&log2(k-1)+1>=n)){
			puts("-1");
			continue;
		}
		for(rgi i=1;i<=n;++i){
			if(a[i])continue;
			int l=i-1,r=n+1;
			while(r>l+1){
				if(check(i,mid)<k)l=mid;
				else r=mid;
			}
			k-=check(i,l);
			for(rgi j=0;l-j>=i;++j)a[i+j]=l-j;
		}
		for(rgi i=1;i<=n;++i)write(a[i],' ');
		puts("");
	}
	return 0;
}