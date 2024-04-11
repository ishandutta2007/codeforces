#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int D = 30, maxn = 1e6 + 3333, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, a[maxn], mn = 1<<30;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	ll ans = 0;
	set<int> x;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		a[t]++;
		x.insert(t);
	}
	for(int i = 1; i <= 200000; i++)
		a[i]+=a[i-1];
	for(auto i : x) {
		ll ar = 0;
		for(int t = i; t <= 200000; t += i) {
			ar += t*(a[min(t+i-1, 200000)]-a[t-1]);
		}
		ans = max(ar, ans);
	}
	cout << ans;
}