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

const int N=100005;

int a[N],b[N],c[N];

int main()
{
	#ifdef LOCAL_TEST
		freopen("d.in","r",stdin);
		freopen("d.out","w",stdout);
	#endif
	int n,x;
	cin>>n>>x;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0,j;i<n;i++) cin>>j,c[j]++;
	sort(a,a+n);
	int ans=0;
	for (int i=n-1,j=max(0,x-a[n-1]);i>=0;i--)
	{
		while (j<=N-5 && (c[j]==0 || a[i]+j<x)) j++;
		if (j>N-5) break;
		ans++;
		c[j]--;
	}
	cout<<1<<" "<<ans<<endl;
	return 0;
}