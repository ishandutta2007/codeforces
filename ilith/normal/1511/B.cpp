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
int t,a,b,c;
int pr[]={1,11,101,1009,99997,100003,1234567,19260817,998244353};
int pr2[]={3,13,103,4483,14369,100007,7645321,39999931,200000011};
signed main(){
	read(t);
	while(t--){
		read(a,b,c);
		write(pr[a-c]);
		for(rgi i=1;i<c;++i)write(0);
		write(' ',pr2[b-c]);
		for(rgi i=1;i<c;++i)write(0);
		puts("");
	}
	return 0;
}