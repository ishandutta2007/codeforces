#pragma GCC optimize("-O2")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#define LL long long
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
LL mul(LL x,LL y,LL mod){
	return (x*y-(LL)((long double)x/mod*y+1e-8)*mod+mod)%mod;
} 
LL qpow(LL x,LL y,LL mod){
	LL re=0;
	while(y){
		if(y&1) re=(re+x)%mod;
		x=(x+x)%mod;y>>=1;
	}
	return re;
}
const int N=1e6+10;
int a[N];
int f[N][5][5];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	int x,y,z,v;
	int ans=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		a[x]++;
	}
	if(m<=2){
		for(int i=1;i<=m;++i) ans+=(a[i]/3);
		printf("%d\n",ans);
		return 0;
	}
	memset(f,-1,sizeof(f));
	f[0][0][0]=0;
	
	for(int i=1;i<=m-2;++i){
		for(int j=0;j<5;++j){
			for(int k=0;k<5;++k){
				if(f[i-1][j][k]==-1) continue;
				x=a[i]-j;
				y=a[i+1]-k;
				z=f[i-1][j][k];
				if(x>3){
					int t=(x-2)/3;
					z+=t;
					x=x-t*3;
				}
				for(int g=0;g<=2;++g){
					if(y<g||a[i+2]<g||x<g) continue;
					if(x-g>=3)v=1;else v=0;
					f[i][k+g][g]=max(f[i][k+g][g],z+g+v);
				} 
			}
		}
	}
	for(int j=0;j<5;++j){
		for(int k=0;k<5;++k){
			z=f[m-2][j][k];
			if(x==-1) continue;
			x=a[m-1]-j;
			y=a[m]-k;
			z=z+(x/3)+(y/3);
			ans=max(z,ans);
		}
	}
	printf("%d\n",ans);
	return 0;
}