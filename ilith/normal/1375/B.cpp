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
int t,x;
int main(){
	read(t);
	while(t--){
		int n,m,fl=0;
		read(n,m);
		for(rgi i=1;i<=n;++i){
			for(rgi j=1;j<=m;++j){
				read(x);
				int k1=(i==1||i==n),k2=(j==1||j==m);
				if(k1&&k2){
					if(x>2){
						fl=1;
					}
				}
				else if(k1||k2){
					if(x>3){
						fl=1;
					}
				}
				else if(x>4){
					fl=1;
				}
			}
		}
		if(fl)puts("NO");
		else{
		puts("YES");
		for(rgi i=1;i<=n;++i){
			for(rgi j=1;j<=m;++j){
				int k1=(i==1||i==n),k2=(j==1||j==m);
				if(k1&&k2){
					write(2,' ');
				}
				else if(k1||k2){
					write(3,' ');
				}
				else write(4,' ');
			}
			write('\n');
		}}
	}
	return 0;
}