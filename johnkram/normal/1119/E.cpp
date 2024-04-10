#include<bits/stdc++.h>
using namespace std;
#define MAXN 300005
#define ll long long
ll ans;
int n,i,j,a[MAXN];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		j=min(a[i]>>1,a[i-1]);
		ans+=j;
		a[i]-=j<<1;
		a[i-1]-=j;
		ans+=a[i]/3;
		a[i]%=3;
		a[i]+=a[i-1];
	}
	cout<<ans<<endl;
	return 0;
}