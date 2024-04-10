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

ll L, R;
// 1 2 4 3 5 7 9 6 8 10 12 14 16 18 20
ll cn(ll x) {
	ll res1 = 0,res2 = 0,cof = 1,res =0,pos = 0 ,sum = 0;
	while (res+cof <= x) {
		res += cof;
		if (pos == 0)res1 += cof;
		else res2 += cof;
		cof *= 2;
		pos ^= 1;
	}
	if (pos == 0) {
		res1 += x - res;
	}
	else {
		res2 += x - res;
	}
	res1 %= MODULO;
	res2 %= MODULO;
	sum += res2 * (res2 + 1);
	sum %= MODULO;
	sum += res1 * res1;
	sum %= MODULO;
	return sum;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> L >> R;
	ll a1 = cn(R);
	ll a2 = cn(L - 1);
	ll res = a1 + MODULO - a2;
	cout << res % MODULO << endl;
}