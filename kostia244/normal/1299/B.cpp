#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 1<<19, mlg = 18, rt = 1<<10, mod = 1e9 + 7;
using ld = long double;
using pi = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<pi> a(n);
	for(auto &i : a) cin >> i.first >> i.second;
	a.pb(a[0]);
	map<pi, int> cnt;
	for(int i = 0; i < n; i++) {
		int x = a[i+1].first-a[i].first, y = a[i+1].second-a[i].second;
		if(x < 0 || (x == 0 && y < 0)) x *= -1, y *= -1;
		cnt[{x, y}]^=1;
	}
	for(auto i : cnt) if(i.second) return cout << "nO", 0;
	cout << "yeS";
}