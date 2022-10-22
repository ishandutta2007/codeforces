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
const int N=110;
int t,n,m;
int b[N][N],k[N][N],ans[N][N];
int c[N*N],cnt;
signed main(){
	read(t);
	while(t--){
		read(n,m),cnt=0;
		memset(k,0,sizeof k);memset(ans,0,sizeof ans);
		for(rgi i=1;i<=n;++i){
			for(rgi j=1;j<=m;++j)read(b[i][j]),c[++cnt]=b[i][j];
		}
		nth_element(c+1,c+m,c+cnt+1);
		int tmp=m;
		for(rgi i=1;i<=n;++i){
			for(rgi j=1;j<=m;++j)if(b[i][j]<c[m])k[i][j]=1,--tmp;
		}
		for(rgi i=1;i<=n;++i){
			for(rgi j=1;j<=m;++j)if(b[i][j]==c[m]&&tmp)--tmp,k[i][j]=1;
		}
		int C=0;
		for(rgi i=1;i<=n;++i){
			for(rgi j=1;j<=m;++j){
				if(k[i][j])ans[i][++C]=b[i][j];
			}
			int now=1;
			for(rgi j=1;j<=m;++j){
				if(!k[i][j]){
					while(ans[i][now])now++;
					ans[i][now]=b[i][j];
				}
			}
			for(rgi j=1;j<=m;++j){
				write(ans[i][j],' ');
			}
			puts("");
		}
	}
	return 0;
}