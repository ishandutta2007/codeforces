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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ints(n);
	vll a(n);
	for(ll &x : a) cin >> x;
	
	ll ans = 0;
	for(int i = 0; i < n; i += 2) {
		ll cur = a[i], mn = a[i] - 1;
		int par = -1;
		for(int j = i + 1; j < n; j++) {
			ll lcur = cur;
			cur += par * a[j];
			if(par == -1) ans += max(0LL, min(mn, lcur) - max(0LL, cur) + 1);
			mn = min(mn, cur);
			if(mn < 0) break;
			par *= -1;
		}
	}
	
	cout << ans << '\n';
	return 0;
}