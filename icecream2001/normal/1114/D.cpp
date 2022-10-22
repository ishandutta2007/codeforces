#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
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
int gcd(int x,int y){
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
const int N=2e5+10;
const LL P=1e9+7;
const LL inf=1e18;
int n;
int f[5050][5050][2];
int c[5050];
int cal(int x,int y){
	if(x==y) return 0;
	else return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
	}
	for(int len=2;len<=n;++len){
		for(int l=1,r=len;r<=n;++l,++r){
			f[l][r][0]=f[l][r][1]=100000000;
			f[l][r][0]=min(f[l][r][0],min(f[l+1][r][0]+cal(c[l],c[l+1]),f[l+1][r][1]+cal(c[l],c[r])));
			f[l][r][1]=min(f[l][r][1],min(f[l][r-1][0]+cal(c[l],c[r]),f[l][r-1][1]+cal(c[r-1],c[r])));
			f[l][r][0]=min(f[l][r][0],f[l][r][1]+cal(c[l],c[r]));
			f[l][r][1]=min(f[l][r][0]+cal(c[l],c[r]),f[l][r][1]);
		}
	}
	printf("%d\n",min(f[1][n][0],f[1][n][1]));
	return 0;
} 
/*

*/