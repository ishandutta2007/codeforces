#include <bits/stdc++.h>

using namespace std;
#define DIM  50007
#define DIM2 507
#define INF 10E16
#define MAXN 107
#define LG 18

typedef long long  ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
struct pp {
	ll a, b;
	bool operator <(const pp& V)const {
		if (a == V.a)return b < V.b;
		return a < V.a;
	}
	bool operator ==(const pp& V)const {
		if (a == V.a && b == V.b)return 1;
		return 0;
	}
};

ll n, k,res1 = 0,res2 = 0;
table D;
graph A;
void dfs(ll x, ll par) {
	D[x][0] = 1;
	for (ll to : A[x]) {
		if (to == par)continue;
		dfs(to,x);
		for (int t = k; t >= 1; t--) {
			D[x][t] += D[to][t - 1];
		}
	}
	res1 += D[x][k];
	for (ll to : A[x]) {
		if (to == par)continue;
		for (int j = 1; j < k; j++) {
			res2 += D[to][j - 1] * (D[x][k - j] - D[to][k - j - 1]);
		}
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		A[x].push_back(y);
		A[y].push_back(x);
	}
	dfs(1, 0);
	//ll res = 0;
	//for (int i = 1; i <= n; i++)res += D[i][k];
	cout << res1+res2/2 << endl;
}
// 011 1