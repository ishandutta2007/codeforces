#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 5050, mod =998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k, ans = 0;
	cin >> n >> k;
	vector<int> a(n), b(k), c;
	for(auto &i : a) cin >> i, i -= &i-&a[0];a.push_back(1<<30);n++;
	for(auto &i : b) cin >> i, --i;b.push_back(a.size()-1);k++;
	int lst = -(1<<30), j = 0;
	for(auto &i : a) {
		if(j < k && b[j] == &i-&a[0]) {++j;
			vector<int> lis;
			for(auto &v : c) if(v >= lst && v <= i) {
				auto it = upper_bound(all(lis), v);
				if(it == lis.end()) lis.push_back(v);
				else *it = v;
			}
			ans += c.size()-lis.size();
			c.clear();
			if(lst > i) return cout << -1, 0;
			lst = i;
		} else {
			c.push_back(i);
		}
	}
	cout << ans << '\n';
	return 0;
}