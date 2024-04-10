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
int t,q,d,u;
int s[11][110];
inline int check(int x,int w){
	while(x){
		if(x%10==w)return 1;
		x/=10;
	}
	return 0;
}
int main(){
	for(rgi w=1;w<=9;w++){
		for(rgi i=w;i<=100;i++){
			if(check(i,w))s[w][i]=1;
			else for(rgi j=w;j<i;++j){
				if(s[w][j]&&s[w][i-j]){
					s[w][i]=1;
					break;
				}
			}
		}
	}
	read(t);
	while(t--){
		read(q,d);
		while(q--){
			read(u);
			if(u>=100||d==1)puts("YES");
			else puts(s[d][u]?"YES":"NO");
		}
	}
	return 0;
}