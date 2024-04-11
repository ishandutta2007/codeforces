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
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char t;
	int n, m;
	cin >> n >> m;
	pair<int, int> lo = {n+1, m+1}, hi = {0, 0};
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> t;
			if(t=='W') continue;
			lo = min(lo, {i, j});
			hi = max(hi, {i, j});
		}
	}
	cout << (lo.first+hi.first)/2 << " " << (lo.second+hi.second)/2 << "\n";
}