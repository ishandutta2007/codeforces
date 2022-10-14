//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
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
ll B = 97;
ll bi = 37;
int n, a[101];
vi h;
map<vi, ll> cnt;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int sz = 15;
	int sz2 = 15;
	int A = (1<<sz)-1;
	for(int msk = 0; msk < 1<<sz; msk++) {
		vi hsh;
		for(int i = 1; i < n; i++) {
			int _a = __builtin_popcount((msk^(a[i]&A)));
			int _b = __builtin_popcount((msk^(a[i-1]&A)));
			hsh.pb(_a-_b);
		}
		cnt[hsh] = msk;
	}
	for(int i = 0; i < n; i++) {
		a[i]>>=sz;
	}

	for(int msk = 0; msk < 1<<sz; msk++) {
		vi hsh;
		for(int i = 1; i < n; i++) {
			int _a = __builtin_popcount((msk^(a[i]&A)));
			int _b = __builtin_popcount((msk^(a[i-1]&A)));
			hsh.pb(_b-_a);
		}
		if(cnt[hsh]) {
			cout << (msk<<sz)+cnt[hsh];
			return 0;
		}
	}
	cout << -1;
}