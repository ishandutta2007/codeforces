#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <bitset>
#include <functional>
#include <chrono>
#include <random>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

const int K = int(2e6) + 10;
const ll M = ll(1e9) + 7;
ll ia[K];

ll inv(ll x) {
	ll t = x, r = 1;
	for(int k = M - 2; k; k >>= 1) {
		if(k & 1) r = r * t % M;
		t = t * t % M;
	}
	return r;
}

ll prob(ll a, ll b) {
	return a * ia[a + b] % M;
}

int n;
ll a[14], pb[14][14], pbb[14][1 << 14], dp[1 << 14][14];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	for(int i = 1; i < K; i++) ia[i] = inv(i);
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) pb[i][j] = prob(a[i], a[j]);
		for(int j = 0; j < (1 << n); j++) {
			pbb[i][j] = 1;
			for(int k = 0; k < n; k++) if((j >> k) & 1) (pbb[i][j] *= pb[i][k]) %= M;
		}
	}
	ll ans = 0;
	for(int x = 0; x < n; x++) {
		for(int st = 1; st < (1 << n); st++) {
			if(((st >> x) & 1) == 0) continue;
			dp[st][x] = 1;
			if(st == (1 << x)) continue;
			for(int i = (st - 1) & st; i; i = (i - 1) & st) {
				int j = st ^ i;
				if(((j >> x) & 1) == 0) continue;
				ll cur = dp[j][x];
				for(int u = 0; u < n; u++) if((i >> u) & 1) cur = cur * pbb[u][j] % M;
				(dp[st][x] += M - cur) %= M; 
			}
		}
		ans = (dp[(1 << n) - 1][x] + ans) % M;
	}
	cout << ans << '\n';
	return 0;
}