#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<vector>
#define LL long long
#define ui unsigned int
#define ull unsigned long long
using namespace std;
  
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
    if(x>9) Out(x/10);
    putchar('0'+x%10);
}
LL gcd(LL x,LL y){
    if(!y) return x;
    return gcd(y,x%y);
}
LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;
    }
    return re;
}
const double eps=1e-6;
const LL inf=1e16;
const int P=998244353;
const int N=200+50;

int n,t;
LL k;
LL a[N],b[N],c[N],A[N],B[N];
LL f[N][N][2],g[N][N][2];
int main(){
	scanf("%d%d%I64d",&n,&t,&k);
	for(int i=1;i<=n;++i){
		a[i]=read();b[i]=read();c[i]=read(); 
	}
	++n;a[n]=c[n]=inf;
	for(int i=1;i<=n;++i){
		A[i]=A[i-1]+a[i];
		B[i]=B[i-1]+b[i];
	}
	LL x,y,u;
	for(int i=1;i<=n;++i){
		for(LL j=0;j<=t;++j){
			for(LL z=0;z<=1;++z){
				f[i][j][z]=g[i][j][z]=inf;
				if(j*b[i]+z*a[i]<=c[i]&&f[i-1][j][z]!=inf){
					f[i][j][z]=f[i-1][j][z];
					x=(z*A[i-1]+j*B[i-1]+k-1)/k;
					if(x*k<=z*A[i]+j*B[i]) g[i][j][z]=x;
				}
				for(LL r=0;r<j;++r)
					if(g[i][r][z]!=inf){
						y=A[i]*z+B[i]*r-g[i][r][z]*k;
						x=(max(0LL,(y+(j-r)*b[i]-c[i]))+k-1)/k;
						if(x*k<=y&&f[i-1][j-r][0]!=inf){
							f[i][j][z]=min(f[i][j][z],g[i][r][z]+x+f[i-1][j-r][0]);
							u=(B[i-1]*(j-r)+k-1)/k;
							if(u*k<=B[i]*(j-r)+y-x*k) g[i][j][z]=min(g[i][j][z],g[i][r][z]+x+u);
						}
					}
			}
		}
	}
	cout<<f[n][t][1]<<endl;
	return 0;
}
/*

*/