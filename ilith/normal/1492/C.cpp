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
const int N=200010;
int t,n,m,ans;
char a[N],b[N];
int pre[N],suf[N];
signed main(){
	read(n,m);
	scanf("%s%s",a+1,b+1);
	int p=1;
	for(rgi i=1;i<=n;++i){
		if(a[i]==b[p]&&p<=m){
			pre[p]=i,++p;
		}
	}
	p=m;
	for(rgi i=n;i>=1;--i){
		if(a[i]==b[p]&&p){
			suf[p]=i,--p;
		}
	}
	for(rgi i=1;i<m;++i){
		ans=max(ans,suf[i+1]-pre[i]);
	}
	write(ans);
    return 0;
}