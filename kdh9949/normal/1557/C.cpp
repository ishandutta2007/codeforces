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
#include <cmath>
#include <cstdio>
#include <cstdlib>
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
	const static ll M = ll(1e9) + 7;
	while(t--) {
		ints(n, k);
		ll ans = 0;
		if(n & 1) {
			ll T = 1;
			for(int i = 0; i < n - 1; i++) T = T * 2 % M;
			++T %= M;
			ans = 1;
			for(int i = 0; i < k; i++) ans = ans * T % M;
		}
		else {
			vll a(k + 1), b(k + 1);
			a[0] = b[0] = 1;
			ll A = 1;
			for(int i = 0; i < n - 1; i++) A = A * 2 % M;
			ll B = 2 * A % M;
			A = (A - 1 + M) % M;
			for(int i = 1; i <= k; i++) {
				a[i] = a[i - 1] * A % M;
				b[i] = b[i - 1] * B % M;
			}
			ans = a[k];
			for(int i = 0; i < k; i++) (ans += a[i] * b[k - 1 - i]) %= M;
		}
		cout << ans << '\n';
	}
	
	return 0;
}