#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
#define ll long long
int n,m,ans,i,j,k,l,f[305][305],a[305],b[305],c[305],d[305],C[305][305];
bool check(ll x)
{
	ll l,r,mid;
	l=0;
	r=1000000001;
	while(l+1<r)
	{
		mid=l+r>>1;
		if(mid*mid<=x)l=mid;
		else r=mid;
	}
	return l*l==x;
}
int main()
{
	scanf("%d",&n);
	for(i=C[0][0]=1;i<305;i++)for(j=C[i][0]=1;j<=i;j++)
	{
		C[i][j]=C[i-1][j]+C[i-1][j-1];
		if(C[i][j]>=P)C[i][j]-=P;
	}
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)if(check((ll)a[i]*a[j]))break;
		if(j<i)b[i]=b[j];
		else b[i]=++m;
		c[b[i]]++;
	}
	for(i=1;i<=m;i++)d[i]=d[i-1]+c[i];
	f[1][c[1]-1]=1;
	for(i=1;i<m;i++)for(j=0;j<d[i];j++)for(k=1;k<=c[i+1];k++)for(l=0;l<=k&&l<=j;l++)f[i+1][j+c[i+1]-k-l]=(f[i+1][j+c[i+1]-k-l]+(ll)f[i][j]*C[j][l]%P*C[d[i]+1-j][k-l]%P*C[c[i+1]-1][k-1])%P;
	ans=f[m][0];
	for(i=1;i<=m;i++)for(j=1;j<=c[i];j++)ans=(ll)ans*j%P;
	cout<<ans<<endl;
	return 0;
}