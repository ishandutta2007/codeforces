#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
int lp[maxn + 1];
vi pr;
vvi curr;

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

void precalc(int n) {
	curr.resize(n + 1);
	for(int i = 2; i <= n; i++) {
		if(lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
			curr[i] = {i};
		} else {
			curr[i] = curr[i / lp[i]];
			curr[i].push_back(lp[i]);
		}
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i <= n; j++) {
			lp[pr[j] * i] = pr[j];
		}
	}
}

int get_am(int a) {
	unordered_map<int, int> d;
	for(const auto& el : curr[a]) {
		++d[el];
	}
	int now = 0;
	for(const auto& el : d) {
		now = gcd(now, el.second);
	}
	return now;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	precalc(n);
	vi am(21, 0);
	vector<bool> here(22 * m, false);
	int now = 0;
	for(int i = 1; i < 21; i++) {
		for(int j = 1; j <= m; j++) {
			if(!here[i * j]) ++now;
			here[i * j] = true;
		}
		am[i] = now;
	}
	ll ans = 1;
	for(int i = 2; i <= n; i++) {
		int here = get_am(i);
		ans += am[here] - am[here - 1];
	}
	cout << ans;
}