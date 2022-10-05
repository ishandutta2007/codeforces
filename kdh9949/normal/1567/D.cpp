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
		ints(s, n);
		int c[11] = {};
		for(int i = 0; s; i++) {
			c[i] = s % 10;
			s /= 10;
		}
		while(true) {
			if(accumulate(c, c + 11, 0) >= n) break;
			for(int i = 1; ; i++) if(c[i]) {
				c[i] -= 1;
				c[i - 1] += 10;
				break;
			}
		}
		for(int t = 0; t < n - 1; t++) {
			for(int i = 0; ; i++) if(c[i]) {
				c[i]--;
				cout << '1';
				for(int j = 0; j < i; j++) cout << '0';
				cout << ' ';
				break;
			}
		}
		int i;
		for(i = 10; ; i--) if(c[i]) break;
		for(; i >= 0; i--) cout << c[i];
		cout << '\n';
	}
	
	return 0;
}