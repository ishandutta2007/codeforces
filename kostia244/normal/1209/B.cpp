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
const int maxn = 1<<20, mod = 998244353, rt = 565042129, i2 = (mod+1)/2;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
bitset<130> a;
int x[130], y[130];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	char t;
	for(int i = 0; i < n; i++) cin >> t, a[i] = t-'0';
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	int ans = a.count();
	for(int i = 0; i < 20000; i++) {
		for(int j = 0; j < n; j++) if(y[j] == i) a.set(j, a[j]^1), y[j] += x[j];
		ans = max(ans, (int)a.count());
	}
	cout << ans;
}