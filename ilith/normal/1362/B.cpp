#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define fi first
#define se second
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
ll t,n,a[N],b[N];
signed main(){
	read(t);
	while(t--){
		read(n);
		for(rgi i=1;i<=n;++i)read(a[i]);
		sort(a+1,a+n+1);
		for(rgi w=1;w<1024;++w){
			int fl=1;
			for(rgi i=1;i<=n;++i){
				b[i]=a[i]^w;
			}
			sort(b+1,b+n+1);
			for(rgi i=1;i<=n;++i){
				if(b[i]!=a[i]){
					fl=0;
					break;
				}
			}
			if(fl){
				write(w,'\n');
				goto tag;
			}
		}
		puts("-1");
		tag:;
	}
	return 0;
}