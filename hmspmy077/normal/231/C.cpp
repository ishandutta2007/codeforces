#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int a[100005];
long long s[100005];

int main()
{
	#ifdef LOCAL_TEST
		freopen("c.in","r",stdin);
		freopen("c.out","w",stdout);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int x=a[0],y=1;
	for (int i=0,j=0;i<n;i++)
	{
		s[i+1]=s[i]+a[i];
		while (1ll*a[i]*(i-j+1)-(s[i+1]-s[j])>m) j++;
		if (i-j+1>y)
		{
			y=i-j+1;
			x=a[i];
		}
	}
	cout<<y<<" "<<x<<endl;
	return 0;
}