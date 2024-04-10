#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 1000000007
#define MAXN 1000005
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int n,i,j,a[MAXN];
char c[MAXN];
int main()
{
	scanf("%d%s",&n,c+1);
	for(i=1;i<=n;i++)
	{
		if(c[i]=='(')a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
		j=min(j,a[i]);
	}
	if(a[n]||j<-1)puts("No");
	else puts("Yes");
	return 0;
}