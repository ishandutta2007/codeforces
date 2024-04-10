#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll s[55],ans;
int n,m,i,j,k,l;
bool f[55][55];
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>s[i];
	for(i=1;i<=n;i++)s[i]+=s[i-1];
	for(i=59;~i;i--)
	{
		ans|=1LL<<i;
		memset(f,0,sizeof(f));
		for(f[0][0]=j=1;j<=m;j++)for(k=j;k<=n;k++)for(l=j;l<=k;l++)f[j][k]|=f[j-1][l-1]&&(s[k]-s[l-1]&ans)==ans;
		if(!f[m][n])ans^=1LL<<i;
	}
	cout<<ans<<endl;
	return 0;
}