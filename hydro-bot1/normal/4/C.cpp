// Hydro submission #626e2df8e219e5653b8f324e@1651387897726
#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int main()
{
	int n;
	cin >> n;
	string s;
	while (n--)
	{
		cin >> s;
		if (m[s] == 0)
		{
			m[s]++;
			cout << "OK" << endl;
		}
		else if (m[s] > 0)
		{
			cout << s << m[s]++ << endl;
		}
	}
	return 0;
}