#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
#define P 998244353
int n,d[MAXN],i,j,k,f[MAXN];
int main()
{
	scanf("%d",&n);
	for(i=f[0]=1;i<=n;i++)f[i]=(ll)f[i-1]*i%P;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		d[j]++;
		d[k]++;
	}
	for(i=1,j=n;i<=n;i++)j=(ll)j*f[d[i]]%P;
	cout<<j<<endl;
	return 0;
}