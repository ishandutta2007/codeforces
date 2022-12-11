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
const int N=100010;
int t,a[N],b[N],n;
signed main(){
	read(t);
	while(t--){
		read(n);
		for(rgi i=1;i<=n;++i){
			read(a[i]);
		}
		sort(a+1,a+n+1,[&](int x,int y){return (x&1)<(y&1);});
		int res=0;
		for(rgi i=1;i<=n;++i){
			for(rgi j=i+1;j<=n;++j)res+=(__gcd(a[i],2*a[j])>1);
		}
		write(res,'\n');
	}
	return 0;
}