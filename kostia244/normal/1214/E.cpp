//#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vector<pi> ans, a;
vi d;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		a.pb({t, i});
	}
	sort(rall(a));
	for(int i = 0; i < n; i++) {
		if(i) {
			ans.pb({2*a[i].second, 2*a[i-1].second});
		}
		d.pb(2*a[i].second);
	}
	for(int i = 0; i < n; i++) {
		int x = i+a[i].first-1;
		ans.pb({d[x], 2*a[i].second+1});
		if(x+1==d.size()) {
			d.pb(2*a[i].second+1);
		}
	}
	for(auto i : ans)
		cout << i.first+1 << " " << i.second+1 << "\n";
}