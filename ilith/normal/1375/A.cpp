#include<bits/stdc++.h>
#define rgi register int
using namespace std;
typedef long long ll;
template<typename T>inline void read(T& A){
	T x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	A=x*f;
}
template<typename T,typename... Ts>inline void read(T& A,Ts&... As){read(A),read(As...);}
inline void write(char ch){putchar(ch);}
template<typename T>inline void write(T A){
	if(A<0)putchar('-'),A=-A;
	if(A>9)write(A/10);
	putchar(A%10+'0');
}
template<typename T,typename... Ts>inline void write(T A,Ts... As){write(A),write(As...);}
int t,n,x;
int main(){
	read(t);
	while(t--){
		read(n);
		for(rgi i=1;i<=n;++i){
			read(x),write(i&1?abs(x):-abs(x),'\n');
		}
	}
	return 0;
}