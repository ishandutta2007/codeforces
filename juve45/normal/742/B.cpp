
#include <bits/stdc++.h>
#define DMAX 250008
using namespace std;

int v[DMAX], x, n, a[DMAX];
long long ans = 0;
int main()
{
	cin >> n >> x;
	for(int i=1;i<=n;i++)
		cin >> a[i], v[a[i]]++;
	for(int i=1;i<=n;i++)
	{
		if(a[i] == 0 || x==0) ans--;
		ans += 1LL*v[a[i]^x];
	}
	cout << ans/2;
}