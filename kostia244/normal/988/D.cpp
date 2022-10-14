#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 5e2 + 10, mlg = 17, mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	set<ll> a;
	int n, x;
	cin >> n;
	while(n--) {
		cin >> x;
		a.insert(x);
	}
	pair<ll, pi> ans = {0, {0, 0}};
	for(auto i : a) {
		for(ll d = 1; d <= 1<<30; d<<=1) {
			ans = max(ans, {1+a.count(i+d)+a.count(i-d), {i, d}});
		}
	}
	cout << ans.first << "\n";
	if(a.count(ans.second.first-ans.second.second)) cout << ans.second.first-ans.second.second << " ";
	cout << ans.second.first << " ";
	if(a.count(ans.second.first+ans.second.second)) cout << ans.second.first+ans.second.second << " ";
	return 0;
}