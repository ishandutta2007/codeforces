#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10;
int p[N],c[N],s[N],n,can;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d%d",&p[i],&c[i]),s[i]=c[i];
	for (int i=1;i<=n;i++)if (p[i]>0)s[p[i]]&=c[i];
	for (int i=1;i<=n;i++)if (s[i])printf("%d ",i),can=1;
	if (!can)printf("-1");
}