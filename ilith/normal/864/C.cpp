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
int a,b,f,k,ans,now,sx;
int dn,dw;
int nxt(){
	return now?2ll*f:2ll*(a-f);
}
signed main(){
	read(a,b,f,k);
	sx=b;
	dn=a*k;
	if(b<f){
		puts("-1");
		return 0;
	}
	b-=f,dw+=f;
	if(b<0){
		puts("-1");
		return 0;
	}
	while(dw<=dn){
		int dis=nxt();
		if(dw+b>=dn){
			write(ans);
			return 0;
		}
		if(dw+sx>=dn){
			write(ans+1);
			return 0;
		}
		if(dis>b)b=sx,++ans;
		b-=dis,dw+=dis;
		if(b<0){
			puts("-1");
			return 0;
		}
		now^=1;
	}
	if(dw<dn){
		puts("-1");
		return 0;
	}
	write(ans);
	return 0;
}