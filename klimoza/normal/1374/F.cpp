/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
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
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

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

const int N = 501;

vector<int> id[N];

int a[N];
int p[N];

vector<int> ans;

void sw(int i) {
	ans.push_back(i);

	int x = a[i], y = a[i + 1], z = a[i + 2];
	a[i] = z, a[i + 1] = x, a[i + 2] = y;
	
	x = p[i], y = p[i + 1], z = p[i + 2];
	p[i] = z, p[i + 1] = x, p[i + 2] = y;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		fill(a, a + n, 0);
		fill(p, p + n, 0);
		ans.clear();
		for (int i = 0; i <= n; i++)
			id[i].clear();
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
			id[a[i]].push_back(i);
		}
		sort(all(b));
		for (int i = 0; i < N; i++)
			sort(rall(id[i]));
		for (int i = 0; i < n; i++) {
			p[id[b[i]].back()] = i;
			id[b[i]].pop_back();
		}
		for (int i = 0; i < (n - 2); i++) {
			int x = 0;
			for (int j = 0; j < n; j++) {
				if (p[j] == i) {
					x = j;
					break;
				}
			}
			while (x != i) {
				if (x - 1 == i) {
					sw(i); sw(i);
					x--;
				}
				else {
					sw(x - 2);
					x -= 2;
				}
			}
		}
		/*for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;*/
		if (a[n - 1] < a[n - 2]) {
			if (a[n - 3] == a[n - 1]) {
				sw(n - 3);
			}
			else {
				int i = -1;
				for (int j = 0; j < n - 1; j++) {
					if (a[j] == a[j + 1]) {
						i = j;
						break;
					}
				}
				if (i == -1) {
					cout << -1 << endl;
					continue;
				}
				while (true) {
					if (i == n - 2) {
						break;
					}
					if (i == n - 3) {
						sw(i);
						sw(i);
						break;
					}
					sw(i + 1);
					sw(i);
					i += 2;
				}
			}
		}
		cout << ans.size() << endl;
		for (int i : ans)
			cout << i + 1 << " ";
		cout << endl;
	}
	return;

}