#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k;

int main()
{
	ios_base::sync_with_stdio(false);
	

	cin >> n >> k;


	int g = 240 - k;
	int ans = 0;

	for(int i=1;i<=n;i++)
	{
		if(ans + 5*i > g )
		{
			cout << i-1 << '\n';
			return 0;
		}
		ans += 5*i;
	}
	cout << n << '\n';

	return 0;
}