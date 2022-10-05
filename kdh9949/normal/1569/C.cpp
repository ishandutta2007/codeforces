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

const int M = 998244353;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	ints(t);
	while(t--) {
		ints(n);
		vint a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(all(a));
		if(a[n - 1] == a[n - 2]) {
			int ans = 1;
			for(int i = 1; i <= n; i++) ans = 1LL * ans * i % M;
			cout << ans << '\n';
		}
		else if(a[n - 1] == a[n - 2] + 1) {
			int cnt = 1, ans = 1;
			while(n - 2 - cnt >= 0 && a[n - 2 - cnt] == a[n - 2]) cnt++;
			for(int i = 1; i <= n; i++) ans = 1LL * ans * (i - (i == cnt + 1 ? 1 : 0)) % M;
			cout << ans << '\n';
		}
		else cout << "0\n";
	}
	
	return 0;
}