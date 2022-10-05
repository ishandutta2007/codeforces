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
	
	int prime[1000] = {};
	for(int i = 2; i <= 999; i++) {
		prime[i] = 1;
		for(int j = 2; j * j <= i; j++) {
			if(i % j == 0) { prime[i] = 0; break; }
		}
	}
	
	ints(t);
	while(t--) {
		ints(n);
		strs(s);
		int ans = n;
		string as = s;
		for(int i = 0; i < n; i++) {
			if(s[i] != '2' && s[i] != '3' && s[i] != '5' && s[i] != '7') {
				ans = 1;
				as = string(1, s[i]);
				break;
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				if(ans > 2 && !prime[10 * (s[i] - '0') + (s[j] - '0')]) {
					ans = 2;
					as = "";
					as.push_back(s[i]);
					as.push_back(s[j]);
				}
				for(int k = i + 1; k < n; k++) {
					if(ans > 3 && !prime[100 * (s[i] - '0') + 10 * (s[j] - '0') + s[k] - '0']) {
						ans = 3;
						as = "";
						as.push_back(s[i]);
						as.push_back(s[j]);
						as.push_back(s[k]);
					}
				}
			}
		}
		cout << ans << '\n' << as << '\n';
	}

	return 0;
}