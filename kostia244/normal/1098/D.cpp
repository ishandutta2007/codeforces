#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<19, mod = 1e9 + 7;
multiset<int> v[33];
ll s[33];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int q, x, n = 0;
	char c;
	cin >> q;
	while(q--) {
		cin >> c >> x;
		int id = __lg(x);
		if(c == '+') v[id].insert(x), s[id] += x, n++;
		else v[id].erase(v[id].find(x)), s[id] -= x, n--;
		if(n < 2) {cout << "0\n"; continue;}
		ll cur = 0, ans = 0;
		for(int i = 0; i < 33; i++) {
			if(v[i].size()) {
				ans += cur && 2ll*cur < *v[i].begin();
			}
			cur += s[i];
		}
		cout << n-1-ans << '\n';
	}
}