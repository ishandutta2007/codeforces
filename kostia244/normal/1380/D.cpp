#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, x, y, k, ans = 0;
ll solve(vector<int> c, int mx) {
	if(c.empty()) return 0;
	int m2 = *max_element(c.begin(), c.end());
	ll tans = 1ll<<60;
	for(int rem = 0; rem <= c.size(); rem++) {
		if(rem == c.size() && m2 > mx) continue;
		if((c.size()-rem)%k) continue;
		ll cost = (c.size()-rem)/k;
		cost = cost*x + y*rem;
		tans = min(tans, cost); 
	}
	if(tans == 1ll<<60) {
		cout << -1;
		exit(0);
	}
	return tans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> x >> k >> y;
	vector<int> a(n), b(m);
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;
	a.push_back(-(1<<30)), b.push_back(-(1<<30)), n++, m++;
	int lst = -1;
	for(auto X : b) {
		int i = lst+1;
		vector<int> c;
		while(i < n && a[i] != X) c.push_back(a[i++]);
		if(i == n) return cout << -1, 0;
		ans += solve(c, max(a[i], lst==-1?-1:a[lst]));
		lst = i;
	}
	cout << ans << endl;
}