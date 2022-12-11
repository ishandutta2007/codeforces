#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

#define forn(i) for (int (i) = 0; (i) <= n; ++i)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Number {
	char cnt[10];
	char len;
	Number() {
		memset(cnt, 0, sizeof(cnt));
		len = 0;
	}
};

vector<Number> numbers;

void rec(Number& n, int d, int len) {
	if (d == 10) {
		if (len == 0) {
			return;
		}
		n.len = len;
		numbers.pb(n);
		return;
	}
	for (int c = 0; c + len <= 18; ++c) {
		n.cnt[d] = c;
		rec(n, d + 1, len + c);
	}
}

vector<int> disperse(ll n) {
	vector<int> ans;
	while (n) {
		ans.pb(n % 10);
		n /= 10;
	}
	reverse(all(ans));
	return ans;
}

bool smallestIsLeq(Number n, bool can, const vector<int>& vct, int pos) {
	/*bool flag = false;
	if (n.cnt[1] == 2 && n.cnt[2] == 1) {
		flag = true;
	}*/
	if (!can) {
		bool put = false;
		for (int i = 1; i < 10; ++i) {
			if (n.cnt[i]) {
				--n.cnt[i];
				put = true;
				if (i < vct[pos]) {
					return true;
				}
				if (i > vct[pos]) {
					return false;
				}
				++pos;
				break;
			}
		}
		if (!put) {
			return false;
		}
	}

	for (int i = 0; i < 10; ++i) {
		while (n.cnt[i]--) {
			/*if (flag) {
				cout << "!" << i << "\n";
			}*/
			if (i < vct[pos]) {
				return true;
			}
			if (i > vct[pos]) {
				return false;
			}
			++pos;
		}
	}
	return true;
}

bool greatestIsGeq(Number n, const vector<int>& vct, int pos) {
	for (int i = 9; i >= 0; --i) {
		while (n.cnt[i]--) {
			if (i > vct[pos]) {
				return true;
			}
			if (i < vct[pos]) {
				return false;
			}
			++pos;
		}
	}
	return true;
}

bool solve(const vector<int>& a, const vector<int>& b, Number n) {
	for (int i = 0; i < sz(a); ++i) {
		for (int j = a[i] + 1; j < b[i]; ++j) {
			if (n.cnt[j]) {
				return true;
			}
		}
		if (a[i] == b[i]) {
			if (!n.cnt[a[i]]) {
				return false;
			}
			--n.cnt[a[i]];
			continue;
		}

		if (n.cnt[a[i]]) {
			Number x = n;
			--x.cnt[a[i]];
			if (greatestIsGeq(x, a, i + 1)) {
				return true;
			}
		}

		if (n.cnt[b[i]]) {
			Number x = n;
			--x.cnt[b[i]];
			if (smallestIsLeq(x, true, b, i + 1)) {
				return true;
			}
		}

		return false;
	}
	return true;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	Number tmp;
	rec(tmp, 1, 0);

	int ans = 0;
	ll lf, rg;
	cin >> lf >> rg;

	/*set<vector<int> > correct;
	for (ll val = lf; val <= rg; ++val) {
		vector<int> t = disperse(val);
		vector<int> v;
		for (int x : t) {
			if (x) {
				v.pb(x);
			}
		}
		sort(all(v));
		correct.insert(v);
	}*/

	vector<int> a = disperse(lf), b = disperse(rg);

	//vector<Number> found;

	for (Number n : numbers) {
		if (n.len > sz(b)) {
			continue;
		}
		while (n.len < sz(a)) {
			++n.cnt[0];
			++n.len;
		}
		if (sz(a) + 1 < sz(b) && n.len < sz(b)) {
			++ans;
			//found.pb(n);
			continue;
		}

		if (sz(a) + 1 == sz(b)) {
			if (n.len == sz(a)) {
				if (greatestIsGeq(n, a, 0)) {
					++ans;
					//found.pb(n);
					continue;
				}
				++n.cnt[0];
				++n.len;
				if (smallestIsLeq(n, false, b, 0)) {
					++ans;
					//found.pb(n);
					continue;
				}
				continue;
			}
			assert(n.len == sz(b));
			if (smallestIsLeq(n, false, b, 0)) {
				++ans;
				//found.pb(n);
				continue;
			}
			continue;
		}

		if (sz(a) != sz(b)) {
			assert(n.len == sz(b));
			if (smallestIsLeq(n, false, b, 0)) {
				++ans;
				//found.pb(n);
				continue;
			}
			continue;
		}

		assert(n.len == sz(a));
		if (solve(a, b, n)) {
			++ans;
			//found.pb(n);
		}
	}

	/*assert(sz(found) == ans);
	for (Number n : found) {
		vector<int> v;
		for (int d = 1; d < 10; ++d) {
			while (n.cnt[d]--) {
				v.pb(d);
			}
		} 
		if (!correct.count(v)) {
			cout << "!";
			for (int d : v) {
				cout << d;
			}
			cout << "\n";
		} else {
			correct.erase(v);
		}
	}

	for (auto v : correct) {
		cout << "?";
		for (int d : v) {
			cout << d;
		}
		cout << "\n";
	}*/

	cout << /*sz(correct) << " " << */ans << "\n";

}