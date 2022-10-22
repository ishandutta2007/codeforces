#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n,q,i,j,a[3][MAXN],x[MAXN],y[MAXN],z[MAXN],s;
int main()
{
	scanf("%d%d",&n,&q);
	while(q--)
	{
		scanf("%d%d",&i,&j);
		a[i][j]^=1;
		if(i==1)
		{
			s-=x[j]+y[j]+z[j];
			x[j]=a[2][j-1]&&a[1][j];
			y[j]=a[2][j]&&a[1][j];
			z[j]=a[2][j+1]&&a[1][j];
			s+=x[j]+y[j]+z[j];
		}
		else
		{
			s-=x[j+1]+y[j]+z[j-1];
			x[j+1]=a[2][j]&&a[1][j+1];
			y[j]=a[2][j]&&a[1][j];
			z[j-1]=a[2][j]&&a[1][j-1];
			s+=x[j+1]+y[j]+z[j-1];
		}
		if(s)puts("No");
		else puts("Yes");
	}
	return 0;
}