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
const int N=200010;
int t,n;
ll a[N],b[N],ans;
int dcd(int x,double mid){
	return (int)(2.0*mid-x);
}
signed main(){
	t=1;
	while(t--){
		read(n),ans=0;
		for(rgi i=1;i<=n;++i){
			read(a[i]);
		}
		for(rgi i=1;i<=n;++i){
			read(b[i]),ans+=a[i]*b[i];
		}
		ll sum=ans;
		for(double mid=1;mid<=n;mid+=0.5){
			ll k=sum;
			for(rgi i=ceil(mid);dcd(i,mid)<=n&&i<=n&&dcd(i,mid)>0;++i){
				int d=dcd(i,mid);
				k-=a[d]*b[d],k-=a[i]*b[i];
				k+=a[d]*b[i],k+=a[i]*b[d];
				ans=max(ans,k);
			}
		}
		write(ans,'\n');
	}
	return 0;
}