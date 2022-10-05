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

	ints(t);
	while(t--) {
		ints(n);
		vint v;
		for(int i = 0; i < n; i++) {
			ints(x);
			if(x & 1) v.push_back(i);
		}
		ll ans = 0;
		if(n % 2) {
			if(v.size() < n / 2 || v.size() > n / 2 + 1) ans = -1;
			else if(v.size() == n / 2) {
				for(int i = 1; i < n; i += 2) ans += abs(i - v[i / 2]);
			}
			else {
				for(int i = 0; i < n; i += 2) ans += abs(i - v[i / 2]);
			}
		}
		else {
			if(v.size() != n / 2) ans = -1;
			else {
				ll cur = 0;
				for(int i = 0; i < n; i += 2) ans += abs(i - v[i / 2]);
				for(int i = 1; i < n; i += 2) cur += abs(i - v[i / 2]);
				ans = min(ans, cur);
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}