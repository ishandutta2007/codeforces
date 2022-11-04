#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vl a(n);
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	auto b = a;
	int q;
	cin >> q;
	vector<int> qu(q);
	for(int i = 0; i < q; i++) {
		cin >> qu[i];
	}
	ll now = 0;
	ll has = 0;
	ll tm = 0;
	for(int i = 0; i < n; i++) {
		ll here = tm;
		ll can = min(here, a[i]);
		here -= can;
		a[i] -= can;
		if(a[i] > 0) {
			can = min(a[i], has);
			a[i] -= can;
			has -= can;
		}
		if(a[i] > 0) {
			ll dt = (a[i] - 1) / (i + 1) + 1;
			tm += dt;
			has += (ll)(i + 1) * dt;
		}
		has -= a[i];
		has += here;
		a[i] = 0;
	}
	ll out = (ll)n * tm - sum;
	a = b;
	vector<ll> ans;
	ans.push_back(tm);
	for(int i = n - 1; i > 0; i--) {
		out -= tm;
		if(out < 0) {
			ll dt = (abs(out) - 1) / i + 1;
			tm += dt;
			out += dt * i;
		}
		ans.push_back(tm);
	}
	for(int i = 0; i < q; i++) {
		if(qu[i] < ans[0]) {
			cout << "-1\n";
			continue;
		}
		int id = upper_bound(ans.begin(), ans.end(), qu[i]) - ans.begin() - 1;
		cout << n - id << '\n';
	}
}