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
const int N=100010;
ll n,a[N];
signed main(){
	read(n),write(1,' ',n,'\n');
	if(n==1){
		read(a[1]),write(-a[1],'\n');
		puts("1 1\n0\n1 1\n0");
		return 0;
	}
	for(rgi i=1;i<=n;++i)read(a[i]),write(-a[i]*n,' ');
	write('\n',2,' ',n,'\n');
	for(rgi i=2;i<=n;++i)write(a[i]*(n-1),' ');
	write('\n',1,' ',1,'\n',a[1]*(n-1));
	return 0;
}