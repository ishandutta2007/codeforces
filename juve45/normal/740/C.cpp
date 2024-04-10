#include <bits/stdc++.h>

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";\n"

using namespace std;
int diff = 10000000, m, n, a, b;
int main()
{
	ios_base::sync_with_stdio(false);

	cin>>n>>m;

	for(int i=1;i<=m;i++)
	{
		cin >> a >> b;
		diff = min(diff, b-a+1);
	}

	cout << diff << '\n';
	for(int i=0;i<n;i++)
		cout << i%diff << ' ';

	return 0;
}