#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k, m, a, b;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> a >> b;
	a--;
	b--;
	cin >> s;

	if(s[a] == s[b])
	{
		cout << 0;
		return 0;
	}
cout << 1;
	return 0;
}