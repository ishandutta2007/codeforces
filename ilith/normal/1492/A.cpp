#include<bits/stdc++.h>
#define int long long
#define rgi register int
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
int t,n;
int a,b,c,d;
inline int calc(int x,int y){
	int tmp=x;
	x=x*(y/x);
	if(x<y)x+=tmp;
	return x-y;
}
signed main(){
	read(t);
	while(t--){
		read(d,a,b,c);
		int s1=min(calc(a,d),calc(b,d));
		write(min(s1,calc(c,d)),'\n');
	}
    return 0;
}