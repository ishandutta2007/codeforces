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
int t;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	vi a;
	cin >> n;
	a = vi(n);
	for(auto &i : a) cin >> i;
	set<int> t(all(a));
	int ans = 0;
	while(t.size()) {
		int x = *t.begin();
		vi rem;
		for(auto &i : t) if(i%x==0) rem.pb(i);
		for(auto i : rem) t.erase(i);
		ans++;
	}
	cout << ans;
}