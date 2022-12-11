#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int ans = 100500;
	map<char, int> m;
	for (int i = 0; i < sz(s); ++i) {
		++m[s[i]];
	}

	ans = min(ans, m['B']);
	ans = min(ans, m['u'] / 2);
	ans = min(ans, m['l']);
	ans = min(ans, m['b']);
	ans = min(ans, m['a'] / 2);
	ans = min(ans, m['s']);
	ans = min(ans, m['r']);
	cout << ans << "\n";

}