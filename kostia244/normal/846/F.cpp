#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1e5 + 55, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll sum = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	map<int, int> lst;
	ll cur = 0;
	for(int t, i = 1; i <= n; i++) {
		cin >> t;
		cur += i-lst[t];
		lst[t] = i;
		sum += (cur<<1)-1;
	}
	ld den = n*1ll*n;
	cout << fixed << setprecision(15) << ld(sum)/den;
}