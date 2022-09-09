#include <cmath>
#include <cstring>

#include <algorithm>
#include <chrono>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

typedef unsigned long long ull;

using namespace std;

const int P = 998244353;

int norm(int x) { return x >= P ? x - P : x; }
int reduce(int x) { return x < 0 ? x + P : x; }
int neg(int x) { return x ? P - x : 0; }
void add(int& x, int y) { if ((x += y - P) < 0) x += P; }
void sub(int& x, int y) { if ((x -= y) < 0) x += P; }
void fam(int& x, int y, int z) { x = (x + y * (ull)z) % P; }
int mpow(int x, unsigned k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = ret * (ull)x % P;
	return ret;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int _ = 200005;
int a[_], cnt[_], ans[_];
bool vis[_];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i = 1; i <= N; ++i) { cin >> a[i]; ++cnt[a[i]]; }
		int as = 0;
		reverse(a + 1, a + N + 1);
		int siz = N;
		while (siz) {
			int tar = 0; while (cnt[tar]) ++tar;
			ans[++as] = tar;
			fill(vis, vis + tar, 1);
			if (!tar) --cnt[a[siz--]];
			while (tar) {
				if (vis[a[siz]]) { vis[a[siz]] = 0; --tar; }
				--cnt[a[siz--]];
				// cerr << "CERR" << siz << ' ' << tar << '\n';
			}
		}
		cout << as << '\n';
		for (int i = 1; i <= as; ++i) cout << ans[i] << " \n"[i == as];
	}

	return 0;
}