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
int t,n,a[N],b[N],sum;
bitset<N>k;
signed main(){
	read(n);
	k[0]=1;
	for(rgi i=1;i<=n;++i){
		read(a[i]),b[i]=a[i],sum+=b[i];
		k|=(k<<a[i]);
	}
	if((sum&1)||!k[sum/2]){
		puts("0");
		return 0;
	}
	puts("1");
	while(1){
		for(rgi i=1;i<=n;++i){
			if(a[i]&1){
				write(i);
				return 0;
			}
			a[i]/=2;
		}
		
	}
	return 0;
}