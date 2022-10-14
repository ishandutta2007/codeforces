#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3e5 + 55;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, a[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int sz = n, p = 0;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		a[t] = i+1;
	}
	int u = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i]<a[i-1]) u = 0;
		ans = max(ans, ++u);
	}
	cout << n-ans;
}