#include <bits/stdc++.h>

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";\n"

using namespace std;

int n, k, g, t;
string s;
int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	cin >> s;

	for(int i=0;i <s.size(); i++)
	{
		if(s[i] == 'G')
			g = i;
		if(s[i] == 'T')
			t = i;
	}

	if(g%k != t%k)
	{
		cout << "NO\n";
		return 0;
	}

	if(g < t)
		swap(g, t);

	while(1)
	{
		if(g == t)
		{
			cout << "YES\n";
			return 0;
		}
		if(s[t] == '#')
		{
			cout << "NO\n";
			return 0;
		}
		t+=k;
	}

	return 0;
}