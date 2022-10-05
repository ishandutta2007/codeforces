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

	ints(n, m);
	vint od(n + 1);
	int ans = n;
	for(int i = 0; i < m; i++) {
		ints(x, y);
		ans -= !od[min(x, y)]++;
	}
	ints(q);
	while(q--) {
		ints(t);
		if(t == 1) {
			ints(x, y);
			ans -= !od[min(x, y)]++;
		}
		else if(t == 2) {
			ints(x, y);
			ans += !--od[min(x, y)];
		}
		else writeln(ans);
	}
	
	return 0;
}