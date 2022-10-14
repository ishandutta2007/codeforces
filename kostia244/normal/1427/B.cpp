#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 3e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n, k;
	cin >> n >> k;
	string s;cin >> s;
	int len = 0;
	vector<int> a;
	int cnt = 0;
	char pr = '\0';
	int ok = 0, ok2 = 0;
	for(auto i : s) {
		if(i == 'L') len++;
		else {
			if(ok&&len) a.push_back(len);
			len = 0;
			cnt += pr != 'W';
		}
		pr = i;
		ok |= i=='W';
	}
	int score = min(n, (int)count(all(s), 'W') + k);
	if((int)count(all(s), 'W') == 0) cnt+=k>0;
	sort(all(a));
	for(auto &i : a) {
		if(k >= i) cnt--, k-= i;
	}
	cout << 2*score - cnt << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
	int t;cin >> t;
	while(t--) {
		solve();
	}
}