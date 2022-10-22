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
int n,q,k,l,r;
int a[N],fre[N],s[N];
int qu(int x,int y){
	if(x>y)return 0;
	return s[y]-s[x-1];
}
signed main(){
	read(n,q,k);
	for(rgi i=1;i<=n;++i)read(a[i]);
	for(rgi i=2;i<n;++i){
		fre[i]=a[i+1]-a[i-1]-2;
		s[i]=s[i-1]+fre[i];
	}
	s[n]=s[n-1];
	while(q--){
		read(l,r);
		if(l==r)write(k-1,'\n');
		else write(qu(l+1,r-1)+a[l+1]+k-a[r-1]-3,'\n');
	}
    return 0;
}