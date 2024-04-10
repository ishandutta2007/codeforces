#include <bits/stdc++.h>

using namespace std;
#define DIM 300007
#define DIM2 200007
#define DIM3 200007
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 998244353
#define fi first
#define sc second
#define pb push_back
#define pu push
#define sz size()
#define po(power) ( 1<<power)
#define schnell ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

typedef  long long ll;
typedef long double ld;
const ld eps = 0.00000001;
const ll MASK(1 << 10);
const ll MC = 5007;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)
ll n, k, A[DIM],V[DIM];
pll S[DIM];
int main()
{
	schnell;
	cin >> n >> k;
	
	forn(i, n) {
		cin >> A[i];
		S[i].fi = A[i - 1]-A[i];
		S[i].sc = i;
		if (i == 1)S[i].first = 0;
	}
	sort(S + 1, S + 1 + n);
	ll res = A[n] - A[1];
	ll move = 1;
	for (ll i = 1; i <= n && move<k; i++) {
		if (V[S[i].sc-1] == 1 || V[S[i].sc+1]==1)continue;

		res += S[i].fi;
		V[S[i].sc - 1] == 1;
		move++;
	}
	cout << res << endl;
	return 0;
}
// (a+k)%(b+k)
// a-b*x;