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

void solve() {
	int q; cin >> q;
	while (q--) {
		string s; cin >> s;
		sort(rall(s));
		int n = s.size();
		vector<pair<char, int>> mem;
		for (int i = 0; i < n; i++) {
			if (mem.empty() || mem.back().first != s[i])
				mem.push_back({ s[i], 0 });
			mem.back().second++;
		}
		sort(all(mem));
		int m; cin >> m;
		vector<char> ans(m, '$');
		vector<int> b(m);
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		while(!mem.empty()){
			int kek = 0;
			for (int i = 0; i < m; i++) {
				if (ans[i] != '$')continue;
				int cur = 0;
				for (int j = 0; j < m; j++) {
					if (ans[j] != '$')
						cur += abs(i - j);
				}
				//cout << c << " " << i << " " << cur << endl;
				if (cur == b[i]) {
					kek++;
				}
			}
			if (mem.back().second < kek)
				mem.pop_back();
			else {
				for (int i = 0; i < m; i++) {
					if (ans[i] != '$') continue;
					int cur = 0;
					for (int j = 0; j < m; j++) {
						if (ans[j] != '$' && ans[j] != mem.back().first)
							cur += abs(i - j);
					}
					//cout << c << " " << i << " " << cur << endl;
					if (cur == b[i]) {
						ans[i] = mem.back().first;
					}
				}
				mem.pop_back();
			}
		}
		for (char c : ans)
			cout << c;
		cout << endl;
	}
	return;

}