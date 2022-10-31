#include <bits/stdc++.h>

using namespace std;
#define DIM 1007
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

ll n,m,A[DIM][DIM],V[DIM][DIM];
vec T[DIM], S[DIM],col[DIM];
int main()
{
	schnell;
	cin >> n >> m;
	forn(i, n)
		forn(j, m) {
		char ch; cin >> ch;
		A[i][j] = ch - 'a' + 1;
		}
	forn(j, m) {
		forn(i, n) {
			if (T[j].empty() || A[i][j] != A[i - 1][j]) {
				T[j].pb(1);
				S[j].pb(i);
				col[j].pb(A[i][j]);
			}
			else T[j][T[j].size() - 1]++;
		}
		
	}
	ll res = 0;
	forn(j, m) {
		fore(2, i, T[j].size() - 1) {
			if (V[j][i - 2] == 1)continue;
			ll si = 0;
			bool check = false;
			if (T[j][i - 2] >= T[j][i - 1] && T[j][i - 1] <= T[j][i])check = true;
			
			ll p = j+1,length = T[j][i-1];
			if (check)si = 1;
			while (check && p<=m) {
				auto it = lower_bound(S[p].begin(), S[p].end(), S[j][i - 1]);
				ll k = it - S[p].begin();
				if (k+1 > S[p].size() - 1 || S[p][k] != S[j][i - 1] || T[p][k]!=T[j][i-1])check = false;
				if (!check || !(T[p][k - 1] >= T[p][k] && T[p][k] <= T[p][k + 1]))check = false;
				if (!check || col[j][i - 2] != col[p][k - 1] || col[j][i - 1] != col[p][k] || col[j][i] != col[p][k + 1])check = false;
				if (check) {
					si++;
					V[p][k - 1] = 1;
				}
				p++;
			}
			res += si * (si + 1) / 2;
			//cout<<res<<endl;
		}
		//cout << endl;
	}
	cout << res << endl;
}
// 1 2 3 2
// 1 3 7