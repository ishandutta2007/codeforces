#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int n,m;
int a[5005];
int b[5005];
map<int,int>ma;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int f(int x){
	int su=0;
	for (int i=2;i*i<=x;i++)if(x%i==0){
		int t=ma[i]?-1:1;
		while(x%i==0)su+=t,x/=i;
	}
	if(x!=1){
		if(ma[x])su--;
		else su++;
	}
	return su;
}
int ini=0;
int g[5005];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)scanf("%d",&b[i]),ma[b[i]]=1;
	for (int i=1;i<=n;i++)ini+=f(a[i]);
	g[1]=a[1];for (int i=1;i<=n;i++)g[i]=gcd(a[i],g[i-1]);
	int off=1;
	for (int i=n;i>=1;i--){
		int tmp=g[i]/off;int k=f(tmp);
		if(k<0){
			ini-=k*i;
			off*=tmp;
		}
	}
	printf("%d\n",ini);
	return 0;
}