#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cmath>
#define eps 1e-5
#define pi 3.1415926535897932384626433832795028841971693993751058209749445923078
using namespace std;
typedef double db;
struct cp{
       db a,b;
       cp operator+(const cp&x)const{return (cp){a+x.a,b+x.b};}
       cp operator-(const cp&x)const{return (cp){a-x.a,b-x.b};}
       cp operator*(const cp&x)const{return (cp){a*x.a-b*x.b,a*x.b+b*x.a};}
};
int N;
void dft(cp*a,int n,int fl=1){
	for (int i=n>>1,j=1;j<n;j++){
		if(i<j)swap(a[i],a[j]);
		int k;for (k=n>>1;i&k;i^=k,k>>=1);i^=k;
	}
	for (int m=2;m<=n;m<<=1){
		cp wm=(cp){cos(fl*2*pi/m),sin(fl*2*pi/m)};
		for (int i=0;i<n;i+=m){
			cp w=(cp){1,0};
			for (int j=i;j<i+(m>>1);j++,w=w*wm){
				cp u=a[j],v=w*a[j+(m>>1)];
				a[j]=u+v;
				a[j+(m>>1)]=u-v;
			}
		}
	}
	if(fl==-1)for (int i=0;i<n;i++)a[i].a/=n;
}
int ini[1000005]={0};
cp a[2097152];
int ans[1000005],tot=0;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	N=1;while(N<=2*m)N<<=1;
	while(n--){
		int x;scanf("%d",&x);
		ini[x]=1;
		a[x]=(cp){1,0};
	}
	dft(a,N);
	for (int i=0;i<N;i++)a[i]=a[i]*a[i];
	dft(a,N,-1);
	for (int i=1;i<=m;i++)
		if(a[i].a<eps && ini[i])ans[++tot]=i;
		else if(a[i].a>eps && !ini[i]){
			printf("NO\n");
			return 0;
		}
	printf("YES\n%d\n",tot);
	for (int i=1;i<=tot;i++){
		if(i>1)printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}