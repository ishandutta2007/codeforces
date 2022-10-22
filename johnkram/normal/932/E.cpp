#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 1000000007
int n,m,s[5005][5005],i,j,k,l,ans;
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int main()
{
	cin>>n>>m;
	for(i=s[0][0]=1;i<=m;i++)for(j=1;j<=i;j++)s[i][j]=(s[i-1][j-1]+(ll)j*s[i-1][j])%P;
	for(i=0,j=l=1,k=Pow(2,P-2);i<=m;j=(ll)j*(n-(i++))%P,l=(ll)k*l%P)ans=(ans+(ll)s[m][i]*j%P*l)%P;
	ans=(ll)ans*Pow(2,n)%P;
	cout<<ans<<endl;
	return 0;
}