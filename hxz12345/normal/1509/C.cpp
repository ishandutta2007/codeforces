#include<bits/stdc++.h>
using namespace std;
long long f[2010][2010],a[100100];
long long n,i,j;
long long sc(int t,int w)
{
	if (f[t][w]!=-1) return f[t][w];
	if (t==w) return 0;
	long long ans=sc(t+1,w);ans=min(ans,sc(t,w-1));
	f[t][w]=ans+a[w]-a[t];
	return f[t][w];
}
int main()
{
	ios::sync_with_stdio(false);cin.tie();cout.tie();
	cin>>n;
	for (i=1;i<=n;i++)
	   for (j=1;j<=n;j++)
	       f[i][j]=-1;
	for (i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cout<<sc(1,n)<<endl;
	return 0;
}