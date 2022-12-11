#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main()
{

	//ifstream cin("strictly-off.in");
	//ofstream cout("strictly-off.out");
	//freopen("input.txt", "r", stdin);
	//freopen("threed.out", "w", stdout);
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<string> names;
	for (char c = 'A'; c <= 'Z'; ++c) {
		string s = "";
		s += c;
		names.pb(s);
		s += "a";
		names.pb(s);
	}

	vector<int> ans(n);
	for (int i = 0; i < k - 1; ++i) {
		ans[i] = i;
	}

	for (int i = k - 1; i < n; ++i) {
		string s;
		cin >> s;
		if (s == "YES") {
			ans[i] = i;
		} else {
			ans[i] = ans[i - k + 1];
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << names[ans[i]] << " ";
	}
	cout << '\n';

}