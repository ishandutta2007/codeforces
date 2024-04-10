#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T, int size>
struct fenwick {
	T a[size];

	/* precondition: pos > 0 */
	void add(int pos, const T& val) {
		while (pos < size) {
			a[pos] += val;
			pos += pos & -pos;
		}
	}

	T sum(int pos) {
		T ret = T();
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

fenwick<ll, 1000005> d1, d2;

ll dp[1000005][4];
int n;
map<int, int> mp;
int a[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		mp[a[i]] = 0;
	}
	int j = 0;
	for (auto& p : mp)
		p.second = ++j;
	for (int i=1; i<=n; i++)
		a[i] = mp[a[i]];
	reverse(a+1, a+n+1);

	ll sol = 0;

	for (int i=1; i<=n; i++) {
		dp[i][1] = 1;
		dp[i][2] = d1.sum(a[i] - 1);
		dp[i][3] = d2.sum(a[i] - 1);
		sol += dp[i][3];

		d1.add(a[i], dp[i][1]);
		d2.add(a[i], dp[i][2]);
	}

	cout << sol << '\n';
}