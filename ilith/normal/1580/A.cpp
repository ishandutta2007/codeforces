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
const int N=510;
int t,n,m,sum[N][N],ans,k[N];
char a[N][N];
int S(int xl,int yl,int xr,int yr){
    return sum[xr][yr]-sum[xl-1][yr]-sum[xr][yl-1]+sum[xl-1][yl-1];
}
signed main(){
	for(read(t);t--;){
		read(n,m),memset(sum,0,sizeof sum),ans=2*N,memset(k,0,sizeof k);
		for(rgi i=1;i<=n;++i){
			scanf("%s",a[i]+1);
			for(rgi j=1;j<=m;++j){
				sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+(a[i][j]=='1');
			}
		}
		for(rgi l=1;l<=m;++l){
			for(rgi r=l+3;r<=m;++r){
			   	for(rgi i=n-3;i;--i){
			        if(i==n-3){
			            k[i]=r-l-1-S(n,l+1,n,r-1)+S(i,l+1,n-1,r-1)+n-i-S(i,l,n-1,l)+n-i-S(i,r,n-1,r);
			        }
					else {
			            k[i]=r-l-1-S(i+3,l+1,i+3,r-1)+S(i,l+1,i+2,r-1)+3-S(i,l,i+2,l)+3-S(i,r,i+2,r);
			            k[i]=min(k[i],k[i+1]+('0'==a[i][l])+('0'==a[i][r])+S(i,l+1,i,r-1));
			        }
			    }
				for(rgi i=1;i<=n-4;++i)ans=min(ans,k[i+1]+r-l-1-S(i,l+1,i,r-1));
		    }
		}
		write(ans,'\n');
    }
	return 0;
}