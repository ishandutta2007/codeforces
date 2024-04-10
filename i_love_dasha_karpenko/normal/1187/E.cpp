#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define DIM2 107
#define INF 10E10
#define MAXN 2750137
#define LG 18
#define MODULO 1000000007
#define fi first
#define sc second
#define pb push_back
#define pu push
#define sz size()
#define po(power) ( 1<<power)
#define schnell ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

typedef long long ll;
typedef long double ld;

const ld eps = 0.00000001;
const ll MASK(1 << 10);

typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)

ll n,D[DIM],N[DIM],ans = 0;
graph A;
void dfs(ll x) {
	N[x] = 1;
	D[x] = 1;
	for (ll to : A[x]) {
		if (D[to] != -1)continue;
		dfs(to);
		D[x] += D[to];
		N[x] += N[to];
	}
	D[x] += N[x]-1;
}
void findans(ll x, ll par) {
	ans = max(ans, D[x]);
	for (ll to : A[x]) {
		if (to == par)continue;
		D[x] -= D[to];
		D[x] -= N[to];
		N[x] -= N[to];
		D[to] += D[x];
		D[to] += N[x];
		N[to] += N[x];
		findans(to, x);
		N[to] -= N[x];
		D[to] -= N[x];
		D[to] -= D[x];
		N[x] += N[to];
		D[x] += D[to];
		D[x] += N[to];
	}
}
int main()
{
	schnell;
	cin >> n;
	forn(i, n - 1) {
		ll x, y; cin >> x >> y;
		A[x].pb(y); A[y].pb(x);
	}
	memset(D, -1, sizeof(D));
	dfs(1);
	findans(1, 0);
	cout << ans << endl;
}
// 1 2 3 2
// 1 3 7