#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=1010;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
double f[N][N];
int n,m;
double dp(int n,int m){
	if(f[n][m])return f[n][m];
	if(n==0)return f[0][m]=1.0/(1.0+m*1.0);
	if(m==0)return f[n][0]=1.0;
	double p=1.0/(1.0+1.0/((1.0*m+1.0)*dp(m,n-1)));
	return f[n][m]=1.0-p+(1.0*m/(1.0*m+1))*(1.0-dp(m-1,n))*p;
}
int main(){
	int n=read(),m=read();
	printf("%.10lf %.10lf\n",dp(n,m),1.0-dp(n,m));
	return 0;
}