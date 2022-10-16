#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k, pos;

int main()
{
	ios_base::sync_with_stdio(false);
	string s;

	cin >> n;

	for(int i=1;i<=n;i++)
	{

		if(pos < 0 || pos > 20000)
		{
			cout << "NO";
			return 0;
		}

		cin >> k >> s;
		if (pos == 0 && s != "South")
		{
			cout << "NO\n";
			return 0;
		}
		if (pos == 20000 && s != "North")
		{
			cout << "NO\n";
			return 0;
		}

		if(s == "North")
			pos-=k;
		if(s == "South")
			pos+=k;

		if(pos < 0 || pos > 20000)
		{
			cout << "NO";
			return 0;
		}
	}

		if(pos != 0)
		{
			cout << "NO";
			return 0;
	}
	cout << "YES";
	return 0;
}