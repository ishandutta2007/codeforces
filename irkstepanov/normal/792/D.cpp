#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

struct state
{
	ll k;
	ll add;
	ll get() const
	{
		return k + add;
	}
};

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll N;
	int q;
	cin >> N >> q;

	while (q--) {
		ll x;
		cin >> x;
		vector<state> prev;
		state curr = {(N + 1) / 2, 0};
		while (curr.get() != x) {
			if (x < curr.get()) {
				prev.pb(curr);
				curr.k /= 2;
			} else {
				prev.pb(curr);
				curr.add += curr.k;
				curr.k /= 2;
			}
		}
		string s;
		cin >> s;
		for (int i = 0; i < sz(s); ++i) {
			if (s[i] == 'U') {
				if (prev.empty()) {
					continue;
				} else {
					curr = prev.back();
					prev.pop_back();
				}
				continue;
			}
			if (curr.get() & 1) {
				continue;
			}
			if (s[i] == 'L') {
				prev.pb(curr);
				curr.k /= 2;
			} else {
				prev.pb(curr);
				curr.add += curr.k;
				curr.k /= 2;
			}
		}
		cout << curr.get() << "\n";
	}

}