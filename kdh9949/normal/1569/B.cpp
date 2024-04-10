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
		strs(s);
		if(count(all(s), '2') == 1 || count(all(s), '2') == 2) { cout << "NO\n"; continue; }
		
		cout << "YES\n";
		vector<vint> ans(n, vint(n));
		int fst = -1, prv = -1;
		for(int i = 0; i < n; i++) {
			if(s[i] == '2') {
				if(prv >= 0) {
					ans[prv][i] = 1;
					ans[i][prv] = -1;
				}
				prv = i;
				if(fst < 0) fst = i;
			}
		}
		if(fst >= 0) {
			ans[prv][fst] = 1;
			ans[fst][prv] = -1;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i == j) cout << 'X';
				else if(ans[i][j] > 0) cout << '+';
				else if(ans[i][j] < 0) cout << '-';
				else cout << '=';
			}
			cout << '\n';
		}
	}
	
	return 0;
}