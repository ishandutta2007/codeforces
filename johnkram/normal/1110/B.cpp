#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,m,i,a[MAXN];
int main()
{
	scanf("%d%*d%d",&n,&m);
	m=n-m;
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<n;i++)a[i]=a[i+1]-a[i]-1;
	sort(a+1,a+n);
	for(i=1;i<=m;i++)n+=a[i];
	cout<<n<<endl;
	return 0;
}