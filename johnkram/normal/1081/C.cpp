#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
int n,m,k,i,j,f[2005][2005];
int main()
{
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)for(f[i][0]=m,j=1;j<i;j++)f[i][j]=(f[i-1][j]+(ll)(m-1)*f[i-1][j-1])%P;
	cout<<f[n][k]<<endl;
	return 0;
}