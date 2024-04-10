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
struct pp { ll a, b; };

ll n, all = 0;
// y-x<x && y+x>y
// y=<2*x && x>=0
// -3 -2
// abs(x-y)<=abs(x) && abs(x+y)>=abs(y) abs(x)<=abs(y) || x+y<=y && x-y>=x
// x<0 x+y=<x
// y<0
// 

bool mycompare(ll x, ll y) {
	return abs(x) < abs(y);
}
parr C;
arr D, A, B;
map<ll, ll> M;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		if (M.count(x) == 0) {
			M[x] = 1;
			all++;
			C[all].first = abs(x);
			if (x < 0)C[all].second = -1;
			else C[all].second = 1;
		}
		else M[x]++;
	}
	sort(C + 1, C + 1 + all);
	ll res = 0;
	for (int i = 1; i <= all; i++) {
		D[i] = D[i - 1] + M[C[i].first * C[i].second];
	}
	for (int i = 1; i <= all; i++) {
		A[i] = C[i].first;
		B[i] = C[i].second;
	}
	n = all;
	for (int i = 1; i <= all; i++) {
		auto it = upper_bound(A + 1 + i, A + 1 + n, A[i] * 2);
		ll k = it - A;
		if (k > n)k = n;
		else k--;
		ll r = D[k] - D[i];
		r *= M[A[i] * B[i]];
		res += r;
	}
	cout << res << endl;
}