//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
int n;
vector<pi> x, y;
bool check(int a, int b) {
	int ans = 0;
	for(int i = 0; ans < 2 && i < n; i++) {
		ans += (x[i].first>a||x[i].second<a)||(y[i].first>b||y[i].second<b);
	}
	return ans < 2;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	x.resize(n);
	y.resize(n);
	vi xo, yo;
	for (int i = 0; i < n; i++) {
		cin >> x[i].first >> y[i].first >> x[i].second >> y[i].second;
		xo.pb(x[i].first);
		yo.pb(y[i].first);
	}
	sort(rall(xo));
	sort(rall(yo));
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			if(check(xo[i], yo[j])) {
				cout << xo[i] << " " << yo[j] << "\n";
				return 0;
			}
		}
	}
}