#include<bits/stdc++.h>
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
const int N=200010;
ll t,n,u,f,ans,k;
int main(){
	read(t);
	while(t--){
		read(n,k,f),k-=f,ans=0;
		while(--n)read(u),ans=!ans?u-f:__gcd(ans,u-f);
		puts(k%ans==0?"YES":"NO");
	}
	return 0;
}