#include <bits/stdc++.h>

using namespace std;
#define DIM 50007
#define DIM2 400007
#define DIM3 200007
#define INF DIM+DIM2
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

typedef  int ll;
typedef long double ld;
const ld eps = 0.00000001;
const ll MASK(1 << 10);
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)

ll q, n, m, lasta, cura, B[DIM2], D[DIM2];
bool read1[DIM2];
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> q;
	forn(h, q) {
		cin >> n >> m;
		//ll a = 0, b = 0;

		forn(j, m) { D[j] = 0; B[j] = 0; }
		lasta = 0;
		cura = 0;
		//ll a, b, numa, numb,fa = 0,fb = 0;
		forn(i, n) {
			lasta = cura;
			cura = 0;
			forn(j, m) {
				if (i != 1 && read1[j]) {
					D[j] = max(D[j], lasta);
				}
				else if (i != 1) {
					D[j] = max(D[j], lasta + 1);
				}
				char ch; cin >> ch;
				if (ch == '*') {
					read1[j] = 1;
					cura++;
					B[j]++;
					//D[j] = max(D[j], A[i]);
				}
				else {
					read1[j] = 0;
				}
			}
		}
		ll res = INF;
		forn(j, m) {
			if (read1[j]) {
				D[j] = max(D[j], cura);
			}
			else {
				D[j] = max(D[j], cura + 1);
			}
			res = min(res, n + m - D[j] - B[j]);
		}

		cout << res << '\n';
	}
	//return 0;
}