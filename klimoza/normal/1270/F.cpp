#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

//#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;
const ll mod2 = mod * mod;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int N = 2e5 + 7;
const int K = 460;
const int M = N * K;

int l[N], r[N];
int kek[N * K + N];

ll stupid(string s) {
	int n = s.size();
	vector<int> pr(n + 1, 0);
	for (int i = 0; i < n; i++) {
		pr[i + 1] = pr[i] + (s[i] == '1');
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (pr[j + 1] != pr[i] && (j - i + 1) % (pr[j + 1] - pr[i]) == 0)
				ans++;
		}
	}
	return ans;
}

ll smart(string s) {
	for (int i = 0; i < N; i++)
		l[i] = -1, r[i] = -1;
	int n = s.size();
	vector<int> p(n + 1);
	p[0] = 0;
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1];
		if (s[i - 1] == '1') p[i]++;
	}
	n++;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (p[i]) {
			//if (p[i] < K) {
				for (int t = 1; t <= min(p[i], K - 1); t++) {
					int pj = p[i] - t;
					if (l[pj] == -1) continue;
					int u1 = (i - r[pj] + t - 1) / t;
					int u2 = (i - l[pj]) / t;
					if (u2 < K) continue;
					u1 = max(u1, K);
					ans += (ll)(u2 - u1 + 1);
				}
			//}
		}
		if (l[p[i]] == -1) {
			l[p[i]] = r[p[i]] = i;
		}
		else {
			r[p[i]]++;
		}
		//cout << cnt[1][2] << endl;
		//cout << i << " " << ans << " " << p[i] << endl;
	}
	for (int k = 1; k < K; k++) {
		for (int i = 0; i < n; i++) {
			int f = i - k * p[i];
			ans += kek[f + M];
			kek[f + M]++;
		}
		for (int i = 0; i < n; i++) {
			int f = i - k * p[i];
			kek[f + M]--;
		}
	}
	return ans;
}

void stress() {
	int cnt = 0;
	while (true) {
		cnt++;
		int n = mrand() % 100 + 1;
		string s = "";
		for (int i = 0; i < n; i++) {
			s += (mrand() % 2 + '0');
		}
		ll a1 = smart(s), a2 = stupid(s);
		if (a1 == a2) cout << "TEST #" << cnt << " OK\n";
		else {
			cout << "TEST #" << cnt << " FAILED\n";
			cout << s << endl;
			cout << a1 << ": smart\n";
			cout << a2 << ": stupid\n";
			return;
		}
	}
}

void solve() {
	//stress();
	string s; cin >> s; cout << smart(s) << endl;
	return;
}