#include <bits/stdc++.h>

#define sz(a) (int)(a).size()
#define pb push_back
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int mod = 1e9 + 7;
const int inf = 1e9;

void add(int& a, int b)
{
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

struct data
{
	int a, b, c;
	data() : a(0), b(-1), c(inf) {}
};

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("wa");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<data> dp(n + 1);
	dp[0].a = 1;
	dp[0].b = 0;
	dp[0].c = 0;

	vector<int> maxx(26);
	for (int i = 0; i < 26; ++i) {
		cin >> maxx[i];
	}

	for (int r = 1; r <= n; ++r) {
		int maxLen = inf;
		for (int l = r; l >= 1; --l) {
			maxLen = min(maxLen, maxx[s[l - 1] - 'a']);
			if (maxLen < r - l + 1) {
				break;
			}
			add(dp[r].a, dp[l - 1].a);
			dp[r].b = max(dp[r].b, max(r - l + 1, dp[l - 1].b));
			dp[r].c = min(dp[r].c, 1 + dp[l - 1].c);
		}
	}

	cout << dp[n].a << "\n" << dp[n].b << "\n" << dp[n].c << "\n";

}