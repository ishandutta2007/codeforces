#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <cstdio>
#include <cstring>
typedef unsigned short ll;
#define M 31607
#define b(x) (1<<((x)-1))
int ksm(int a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll n,a[2250000],b[2250000];
int i,j,k,tmp[22][2250000],ans,sb[66][66];
inline void get() {
	for (int i=0; i<b(n+1); i++){a[i]=(int)a[i]*b[i]%M;}
}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
void fwt(ll *a,int ty){
    for(int s=2;s<=b(n+1);s<<=1){
        int t=(s>>1);
        for(int i=0;i<b(n+1);i+=s){
            for(int j=0;j<t;j++){
                if(!ty){a[i+j]=su(a[i+j],a[i+j+t]);}
				else{a[i+j]=su(a[i+j],M-a[i+j+t]);}
            }
        }
    }
}
int get(int x,int y){
	memset(a,0,sizeof(a));
	memset(a,0,sizeof(b));
	for(i=0;i<b(n+1)-1;i++){
		if(x&&!(i&b(n))){continue;}
		if(y&&!(i&b(1))){continue;}
		a[i]=tmp[1][i];
	}
	fwt(a,0);
	for(i=2;i<=n;i++){
		for(j=0;j<b(n+1)-1;j++){
			if(x&&!(j&b(n+1-i))){b[j]=0;continue;}
			if(y&&!(j&b(i))){b[j]=0;continue;}
			b[j]=tmp[i][j];
		}
		fwt(b,0);get();
	}
	fwt(a,1);
	return a[0];
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&sb[i][j]);
			sb[i][j]=sb[i][j]*ksm(10000,M-2)%M;
		}
	}
	for(i=1;i<=n;i++){
		for(j=0;j<b(n+1);j++){
			tmp[i][j]=1;
			for(k=1;k<=n;k++){
				if(j&b(k)){tmp[i][j]=tmp[i][j]*sb[i][k]%M;}
				else{tmp[i][j]=tmp[i][j]*(1+M-sb[i][k])%M;}
			}
		}
	}
	ans=(1+M-(get(0,0)-get(0,1)-get(1,0)+get(1,1)+M*4)%M)%M;
	printf("%d",ans);
}