#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n,i,ans,a[MAXN];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)if(a[i]!=a[1]&&a[i]!=a[n])ans++;
	cout<<ans<<endl;
	return 0;
}