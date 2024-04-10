#include<bits/stdc++.h>
#define int long long
#define rgi register int
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
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),putchar(' '),write(As...);}
const int N=100010;
int t,n;
int a[N],b[N],c[N];
signed main(){
	read(t);
	while(t--){
		read(n);
		for(rgi i=1;i<=n;++i)read(c[i]);
		for(rgi i=1;i<=n;++i)read(a[i]);
		for(rgi i=1;i<=n;++i)read(b[i]);
		int ans=0,res=0;
		for(rgi i=2;i<=n;++i){
			if(a[i]!=b[i]){
				if(i==2)res+=abs(a[i]-b[i]);
				else res=max(res+min(a[i],b[i])-1+c[i-1]-max(b[i],a[i]),abs(a[i]-b[i]));
			}
			else res=0;
			res+=2;
			ans=max(ans,res+c[i]-1);
		}
		write(ans,'\n');
	}
	return 0;
}

/*

1
3
3 5 2
-1 1 1
-1 3 5

*/