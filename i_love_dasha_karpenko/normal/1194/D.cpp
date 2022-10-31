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

ll t, n, k;
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	forn(h, t) {
		cin >> n >> k;
		if (k % 3 != 0) {
			if (n % 3 != 0)cout << "Alice" << endl;
			else cout << "Bob" << endl;
		}
		else {
			if (n % (k + 1) != k && n % (k + 1) % 3 == 0)cout << "Bob" << endl;
			else cout << "Alice" << endl;
		}

	}

}
// 1 1 1 1 1 1 1 1
// 8 4
//   A      A