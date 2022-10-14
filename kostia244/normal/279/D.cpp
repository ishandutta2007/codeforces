#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
}
template<typename X, typename Y>
istream& operator>>(istream& in, pair<X, Y> &a) {
	in >> a.first >> a.second;
	return in;
}
template<typename T>
void getv(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv(vector<T>& v, int n, Ns ... ns) {
	v.resize(n);
	for (auto& i : v)
		getv(i, ns...);
}
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef ll _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, dp[1<<23], cn[25][25];
vi a;
int maxbit(int x){
	return 31-__builtin_clz(x);
}

int main() {
	doin();
	cin >> n;
	getv(a, n);
	for(int i = 1; i < n; i++) {
		bool ok = false;
		for(int j = 0; j < n; j++){
			cn[i][j] = -1;
			for(int k = 0; k <= j; k++) {
				if(a[j]+a[k]==a[i])
				{
					cn[i][j] = k;
					cn[i][k] = j;
					ok = true;
				}
			}
		}
		if(!ok)
			return cout << -1, 0;
	}
	dp[1]=1;
	for(int msk = 1; msk < 1<<(n-1); msk++){
		if(!dp[msk]) continue;
		int get = maxbit(msk)+1;
		bool ok = false;
		for(int i = 0; !ok && i < (n-1); i++) {
			if(((msk>>i)&1) && cn[get][i]!=-1 && ((msk>>cn[get][i])&1))
				ok = true;
		}
		if(!ok) continue;
		dp[msk |(1<<get)] = 1;
		for(int i = 0; i < (n-1); i++) {
			if((msk>>i)&1) {
				dp[(msk^(1<<i))|(1<<get)] = 1;
			}
		}
	}
	int ans = INT_MAX;
	for(int msk = (1<<(n-1)); msk < 1<<n; msk++)
		if(dp[msk]) ans = min(ans, __builtin_popcount(msk));
	if(ans == INT_MAX)
		cout << -1;
	else
		cout << ans;
}