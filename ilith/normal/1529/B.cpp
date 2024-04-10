#include<bits/stdc++.h>
#define int ll
#define rgi register int
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
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
int a[N];
signed main(){
	read(t);
	while(t--){
		read(n);
		int ans=0;
		for(rgi i=1;i<=n;++i)read(a[i]);
		sort(a+1,a+n+1);
		int mx=1e10;
		int pos1=n,pos2=1;
		for(rgi i=2;i<=n;++i){
			mx=min(mx,a[i]-a[i-1]);
			if(mx<a[i]){
				pos1=i-1;
				break;
			}
		}
		mx=1e10;
		for(rgi i=n-1;i;--i){
			mx=min(mx,a[i+1]-a[i]);
			if(mx<a[n]){
				pos2=i+1;
				break;
			}
		}
		write(max(pos1,n-pos2+1),'\n');
	}
	return 0;
}