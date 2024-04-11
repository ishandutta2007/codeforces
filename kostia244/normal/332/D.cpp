#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7, rt = 565042129, i2 = (mod+1)/2;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ld = long double;
ld bruh(int n, int k, int Y) {
	if(Y<k) return 0;
	vi x, y;
	for(int i = 1; i < Y; i++) x.pb(i);
	for(int i = 1; i <= n-k; i++) x.pb(i);
	x.pb(k);
	
	for(int i = 1; i <= n; i++) y.pb(i);
	for(int i = 1; i <= Y-k; i++) y.pb(i);
	
	ld res = 1;
	int i = 0, j = 0;
	while(i < x.size() || j < y.size()) {
		if(i < x.size() && res < 1.) res *= x[i++];
		else res /= y[j++];
	}
	return res;
}
ll n, k, sm[maxn], cnt[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for(int t, i = 1; i < n; i++)
		for(int j = i+1; j <= n; j++) {
			cin >> t;
			if(t == -1) continue;
			sm[i] += t, sm[j] += t;
			cnt[i]++, cnt[j]++;
		}
	ld res = 0;
	for(int i = 1; i <= n; i++) {
		res += bruh(n, k, cnt[i])*sm[i];
	}
	cout << fixed << setprecision(0) << floor(res + 1e-6);
}