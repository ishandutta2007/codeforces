#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define int long long
int N, M, T, a, b, c, d;
string s;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> s;
		N = s.length();
		int ans = 0;
		int i;
		for (i = 0; i < N; i++)
		{
			ans += s[i] - '0';
		}
		int rans = ans;
		for (i = 0; i < N; i++)
		{
			ans += s[i] == '0' ? 1 : -1;
			rans = min(rans, ans);
			rans = min(rans, N-ans);
		}
		cout << rans << '\n';
	}
}