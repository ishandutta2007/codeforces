#include <bits/stdc++.h>

using namespace std;
#define DIM  107
#define DIM2 107
#define INF 10E16
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

ll n,k;
string s;
ll M[DIM][DIM],A[DIM],val[DIM];
int main()
{
	schnell;
	cin >> n >> k;
	cin >> s;
	fore(0, i, n - 1) {
		A[i + 1] = s[i] - 96;
	}
	ll comb = 1;
	for (ll i = n; i >= 1;i--) {
		ll f = 0;
		for (ll j = i + 1; j <= n; j++) {
			
			for (ll h = 1; h <= n; h++) {
				M[i][h + 1] += M[j][h];
				M[i][h + 1] = min(k+1, M[i][h + 1]);
				val[h + 1] += M[j][h];
				val[h + 1] = min(k+1, val[h + 1]);
				ll cof = min(k+1, M[j][h]+comb);
				comb = cof;
			}
			if (A[i] == A[j]) {
				f = 1; break;
			}
		}
		if (f == 0) {
			M[i][1] = 1;
			val[1]++;
			comb++;
		}
	}
	if (k > comb) {
		cout << -1 << endl;
		return 0;
	}
	ll res = 0;
	val[0] = 1;
	for (ll i = n; i >= 0 && k > 0; i--) {
		ll cof = min(val[i], k);
		k -= cof;
		res += cof * (n - i);
	}
	cout << res << endl;
}
// 1 2 3 2
// 1 3 7