#include <bits/stdc++.h>

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";\n"

using namespace std;

int n, a[102], m, ans, l, r;

int main()
{
	ios_base::sync_with_stdio(false);


	cin>>n;


	cin>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i] += a[i-1];
	}

	for(int i=1;i<=m;i++)
	{
		cin >> l >> r;
	
		if(a[r] - a[l-1] > 0) ans += a[r] - a[l-1];
	}

	cout << ans << '\n';
	return 0;
}