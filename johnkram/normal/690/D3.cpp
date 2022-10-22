#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define ll long long
#define P 1000003
ll t[105][105];
struct node
{
	int r,c,a[105][105];
	void operator*=(const node& y)
	{
		register int i,j,k;
		memset(t,0,sizeof(t));
		for(i=0;i<r;i++)for(j=0;j<c;j++)for(k=0;k<y.c;k++)t[i][k]+=(ll)a[i][j]*y.a[j][k];
		c=y.c;
		for(i=0;i<r;i++)for(j=0;j<c;j++)a[i][j]=t[i][j]%P;
	}
}S,A;
int N,n,m,i,j;
int Pow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=(ll)a*a%P)if(b&1)s=(ll)s*a%P;
	return s;
}
int main()
{
	cin>>N>>n>>m;
	S.r=1;
	S.c=A.r=A.c=n+1;
	for(i=0;i<=n;i++)S.a[0][i]=Pow(m+1,i);
	for(i=0;i<n;i++)A.a[i+1][i]=1;
	for(i=0;i<=n;i++)A.a[i][n]=Pow(m,n-i);
	if(N<n)
	{
		printf("%d\n",S.a[0][N]);
		return 0;
	}
	for(N-=n;N;N>>=1,A*=A)if(N&1)S*=A;
	printf("%d\n",S.a[0][n]);
	return 0;
}