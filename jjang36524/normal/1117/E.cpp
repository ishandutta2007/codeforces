#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define int long long
#define MOD 1000000007
int arr[10010];
string res;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string c;
	cin >> c;
	res = c;
	int i;
	for (i = 1; i < 1000; i *= 26)
	{
		string x;
		int j;
		for (j = 0; j < c.size(); j++)
		{
			x.push_back((j / i % 26) + 'a');
		}
		cout << "? " << x << '\n';
		cout.flush();
		string y;
		cin >> y;
		for (j = 0; j < c.size(); j++)
		{
			arr[j] += i * (y[j] - 'a');
		}
	}
	for (i = 0; i < c.size(); i++)
	{
		res[arr[i]] = c[i];
	}
	cout << "! "<<res << '\n';
	cout.flush();
}