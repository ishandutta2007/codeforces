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
const int N=310;
int n,m,u,v,x,y,ans;
int d[11][N][N],f[N][N],tmp[N][N];
void mul(int x[N][N],int a[N][N],int b[N][N]){
	for(rgi i=1;i<=n;++i){
		for(rgi j=1;j<=n;++j){
			for(rgi k=1;k<=n;++k)x[i][j]=max(x[i][j],a[i][k]+b[k][j]);
		}
	}
}
void out(int x[N][N]){
	for(rgi i=1;i<=n;++i){
		for(rgi j=1;j<=n;++j){
			write(x[i][j],' ');
		}
		puts("");
	}
	puts("");
}
int check(){
	for(rgi i=1;i<=n;++i)if(f[i][i]>0)return 1;
	return 0;
}
signed main(){
	read(n,m);
	memset(d,0xcf,sizeof d);
	memset(f,0xcf,sizeof f);
	memset(tmp,0xcf,sizeof tmp);
	for(rgi i=1;i<=n;++i)d[0][i][i]=f[i][i]=tmp[i][i]=0;
	for(rgi i=1;i<=m;++i){
		read(u,v,x,y);
		d[0][u][v]=x,d[0][v][u]=y;
	}
	for(rgi i=1;i<=9;++i)mul(d[i],d[i-1],d[i-1]);
	for(rgi i=9;~i;--i){
		memset(f,0xcf,sizeof f);
		for(rgi i=1;i<=n;++i)f[i][i]=0;
		mul(f,tmp,d[i]);
		if(!check()){
			ans+=(1<<i);
			for(rgi i=1;i<=n;++i)for(rgi j=1;j<=n;++j)tmp[i][j]=f[i][j];
		}
	}
	write(ans>n?0:ans+1);
	return 0;
}