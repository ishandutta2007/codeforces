#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10E16
#define MAXN 10000007
#define MODULO 1000000007 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];

ll n, t, res,y;
void get(ll L, ll R) {
	for (int i = L; i <= R; i++)if (i!=1)cout << i << ' ';
	cout << endl;
}
ll bin(ll L, ll R) {
	ll prev = y;
	while (L != R) {
		ll tm = (R + L) / 2;
		cout << 1 << ' ' << tm - L + 1 << ' ' << 1 << ' ';
		get(L, tm);
		ll r1, r2;
		cin >> r1;
		if (r1 !=y)L = tm + 1;
		else R = tm ;
	}
	return R;
}
int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	cin >> t;
	for (int h = 1; h <= t; h++) {
		cin >> n;
		cout << 1 << ' ' << n - 1 << ' ';
		for (int i = 1; i <= n; i++)cout << i << ' ';
		cout << endl;
		cin >> y;
		ll k = bin(2, n);
		cout << 1 << ' ' << n - 1 << ' ' << k << ' ';
		for (int i = 1; i <= n; i++) {
			if (i != k)cout << i << ' ';
		}
		cout << endl;
		ll res;
		cin >> res;
		cout << -1 << ' ' << res << endl;
	}

}