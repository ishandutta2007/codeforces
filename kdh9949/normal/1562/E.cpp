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

const int K = 5005;
char s[K];
int lcp[K][K], d[K];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	ints(t);
	while(t--) {
		ints(n);
		cin >> (s + 1);
		for(int i = n; i >= 1; i--) {
			for(int j = n; j > i; j--) {
				lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			d[i] = n + 1 - i;
			for(int j = 1; j < i; j++) {
				int t = lcp[j][i];
				if(i + t <= n && s[j + t] < s[i + t]) d[i] = max(d[i], d[j] + n + 1 - (i + t));
			}
			ans = max(ans, d[i]);
		}
		cout << ans << '\n';
	}

	return 0;
}