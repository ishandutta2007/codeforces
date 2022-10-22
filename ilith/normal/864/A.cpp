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
const int N=100010;
int cnt,n,u,s[100010],ans;
int a,b;
int main(){
	read(n);
	for(int i=1;i<=n;++i){
		read(u);
		if(!(s[u]++))++cnt;
		if(cnt>2){
			puts("NO");
			return 0;
		}
	}
	for(rgi i=1;i<=100;i++){
		if(!ans){
			ans+=s[i];
			if(s[i])a=i;
		}
		else{ans-=s[i];
			if(s[i])b=i;
		}
	}
	if(!ans)puts("YES"),printf("%d %d",a,b);
	else puts("NO");
	return 0;
}