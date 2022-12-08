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

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

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

struct Item {
	int m, c;
	string ans = "";
	Item() {}
	Item(int m, int c, string ans) : m(m), c(c), ans(ans) {}
};

const int N = 5e3 + 10;
const int K = 510;

bool dp[N][K];
int h[N];

void bfs(int s, int d) {
	queue<Item> qu;
	string tmp = "";
	for (int i = 1; i < 10; i++) {
		dp[i][i % d] = true;
		qu.push({ i % d, i, tmp + (char)(i + '0') });
	}
	while (!qu.empty()) {
		auto v = qu.front();
		qu.pop();
		if (v.m == 0 && v.c == s) {
			cout << v.ans << endl;
			return;
		}
		for (int k = 0; k < 10; k++) {
			if (v.c + k <= s && !dp[v.c + k][h[(v.m * 10 + k)]]) {
				dp[v.c + k][h[(v.m * 10 + k)]] = true;
				qu.push({ h[(v.m * 10 + k)], v.c + k, v.ans + (char)(k + '0') });
			}
		}
	}
	cout << -1 << endl;
}

void solve() {
	int d, s; cin >> d >> s;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < 10; k++) {
				dp[i][j] = false;
			}
		}
		h[i] = i % d;
	}
	bfs(s, d);
}