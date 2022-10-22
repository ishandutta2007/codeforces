#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
#define ll long long
int f[200005],g[200005],a[200005],b[200005],c[10][10],n,m,N,i,j,ans;
int Pow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=(ll)a*a%P)if(b&1)s=(ll)s*a%P;
	return s;
}
int main()
{
	c[0][0]=c[1][0]=c[1][1]=c[2][0]=c[3][0]=c[3][2]=c[4][0]=c[4][4]=1;
	c[2][1]=c[4][2]=2;
	c[2][2]=c[3][1]=c[3][3]=P-1;
	for(i=f[0]=1;i<200005;i++)f[i]=(ll)f[i-1]*i%P;
	for(g[200004]=Pow(f[200004],P-2),i=200003;~i;i--)g[i]=(ll)g[i+1]*(i+1)%P;
	scanf("%d",&n);
	n--;
	m=n&3;
	N=n-m>>1;
	for(i=0;i<=m;i++)for(j=i;j<=n;j+=2)b[j]=(b[j]+(ll)c[m][i]*f[N]%P*g[j-i>>1]%P*g[N-(j-i>>1)])%P;
	for(i=0;i<=n;i++)
	{
		scanf("%d",a+i);
		ans=(ans+(ll)a[i]*b[i])%P;
	}
	cout<<ans<<endl;
	return 0;
}