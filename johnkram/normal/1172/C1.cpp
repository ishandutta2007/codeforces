#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
#define P 998244353
int n,m,i,j,k,s[2],s0,s1,a[MAXN],b[3005][3005],b0,b1,d[MAXN],f[MAXN];
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int main()
{
	scanf("%d%d",&n,&m);
	b[0][0]=1;
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)scanf("%d",d+i);
	for(i=1;i<=n;i++)s[a[i]]+=d[i];
	for(i=-m;i<=m;i++)f[i+m]=Pow(s[0]+s[1]+i,P-2);
	for(i=0;i<m;i++)for(j=0;j<=i;j++)if(b[i][j])
	{
		k=f[j*2-i+m];
		b[i+1][j]=(b[i+1][j]+(ll)b[i][j]*k%P*(s[0]-i+j))%P;
		b[i+1][j+1]=(b[i+1][j+1]+(ll)b[i][j]*k%P*(s[1]+j))%P;
	}
	s0=Pow(s[0],P-2);
	s1=Pow(s[1],P-2);
	for(i=0;i<=m;i++)
	{
		b0=(b0+(ll)i*b[m][m-i])%P;
		b1=(b1+(ll)i*b[m][i])%P;
	}
	b0=(P-b0)%P;
	for(i=1;i<=n;i++)if(a[i])printf("%d\n",(d[i]+(ll)b1*d[i]%P*s1)%P);
	else printf("%d\n",(d[i]+(ll)b0*d[i]%P*s0)%P);
	return 0;
}