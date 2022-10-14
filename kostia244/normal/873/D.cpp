#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<18, mod = 998244353 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, k, a[maxn];
int C = 1;
void build(int l, int r) {
	--k;
	if(k < 2 || l >= r) {
		while(l<=r) a[l++] = C++;
		return;
	} else {
		int mid = (l+r)/2 - ((r-l)%2 == 0);
		--k;
		build(mid+1, r);
		++k;
		build(l, mid);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	build(1, n);
	if(k) return cout << -1, 0;
	for(int i = 1; i <= n; i++) cout << a[i] << " ";
	return 0;
}