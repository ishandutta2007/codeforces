#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int f[MAXN],d[MAXN],a[MAXN],n,ans,i;
int main()
{
	scanf("%d",&n);
	a[0]=1;
	for(i=2;i<=n;i++)
	{
		scanf("%d",f+i);
		d[i]=d[f[i]]+1;
		a[d[i]]++;
	}
	for(i=0;i<=n;i++)ans+=a[i]&1;
	cout<<ans<<endl;
	return 0;
}