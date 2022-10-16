#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	if(n==1)
	{
	    cout << -1;
	    return 0;
	}
	cout << n << ' ' << n+1 << ' ' << n*(n+1) << '\n';

	return 0;
}