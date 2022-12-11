#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

vector<string> v;

string s;
int rem = 0;
int n;

void solve(set<int> pos)
{
	string t = "";
	int cnt = 0;
	for (int x : pos) {
		cnt = (cnt + (s[x] - '0')) % 3;
	}
	if (cnt != rem) {
		return;
	}
	bool zero = true;
	bool foundZero = false;
	for (int i = 0; i < n; ++i) {
		if (pos.count(i)) {
			continue;
		}
		if (s[i] == '0') {
			foundZero = true;
		}
		if (s[i] == '0' && zero) {
			continue;
		} else {
			zero = false;
			t += s[i];
		}
	}
	if (t == "" && foundZero) {
		t = "0";
	}
	if (t != "") {
		v.pb(t);
	}
}

bool bit(int mask, int pos)
{
	return (mask >> pos) & 1;
}

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	deque<int> pos1, pos2;
	n = sz(s);
	for (int i = 0; i < n; ++i) {
		rem = (rem + (s[i] - '0')) % 3;
		if ((s[i] - '0') % 3 == 1) {
			pos1.pb(i);
			if (sz(pos1) > 2) {
				pos1.pop_front();
			}
		}
		if ((s[i] - '0') % 3 == 2) {
			pos2.pb(i);
			if (sz(pos2) > 2) {
				pos2.pop_front();
			}
		}
	}

	if (rem == 0) {
		cout << s << "\n";
		return 0;
	}

	for (int mask1 = 0; mask1 < (1 << sz(pos1)); ++mask1) {
		for (int mask2 = 0; mask2 < (1 << sz(pos2)); ++mask2) {
			set<int> q;
			for (int i = 0; i < sz(pos1); ++i) {
				if (bit(mask1, i)) {
					q.insert(pos1[i]);
				}
			}
			for (int i = 0; i < sz(pos2); ++i) {
				if (bit(mask2, i)) {
					q.insert(pos2[i]);
				}
			}
			solve(q);
		}
	}

	string ans = "";
	for (string& t : v) {
		if (sz(t) > sz(ans)) {
			ans = t;
		}
	}

	if (sz(ans) == 0) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}

}