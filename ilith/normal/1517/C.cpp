#include<bits/stdc++.h>
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
const int N=510;
int t,n,m;
int a[N][N];
signed main(){
	read(n);
	for(rgi i=1;i<=n;++i){
		read(a[i][i]);
	}
	for(rgi i=0;i<n;++i){
		int cled=0;
		for(rgi j=1;j<=n;++j){
			if(a[j][j-i]==i+1)cled=1;
			else{
				if(cled)a[j][j-i-1]=a[j][j-i];
				else a[j+1][j-i]=a[j][j-i];
			}
		}
		for(rgi j=1;j<=i+1;++j){
			write(a[i+1][j],' ');
		}
		puts("");
	}
	return 0;
}