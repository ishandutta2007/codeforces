#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxv=5e5+105;
int a[maxn],s[maxn];
double c[maxv][6];
double f[maxn][105];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int C(int n,int m){
	double c=1;
	int p=1;
	for(int i=n;i>=n-m+1;i--,p++)c=c*i/p;
	return c;
}
int main(){
	int n,q;
	double ans=0;
	n=read();
	for(int i=1;i<=n;i++){
		s[i]=a[i]=read();
		f[i][a[i]]=1;
		if(a[i]==0)ans+=1;
	}
	c[0][0]=1;
	for(int i=1;i<=500100;i++){
		c[i][0]=1;
		for(int j=1;j<=5;j++)c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	q=read();
	for(int i=1;i<=q;i++){
		int u,v,k;
		u=read();v=read();k=read();
		ans-=f[u][0];
		for(int x=0;x<=a[u];x++){
			int y=s[u]-x;
			double g=f[u][x];f[u][x]=0;
			for(int p=max(k-y,0);p<=min(k,x);p++)
				f[u][x-p]+=g*c[x][p]*c[y][k-p]/c[x+y][k];
		}
		s[u]-=k;s[v]+=k;
		ans+=f[u][0];
		printf("%.9f\n",ans);
	}
	return 0;
}