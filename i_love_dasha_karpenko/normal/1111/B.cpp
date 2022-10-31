#include <bits/stdc++.h>

using namespace std;
#define DIM 100007
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

ll n, k, m, A[DIM],pref[DIM];

int main()
{
	schnell;
	cin >> n >> k >> m;
	ld res = 0.0;
	forn(i, n) {
		cin >> A[i];
		res += A[i];
		
	}
	
	sort(A + 1, A + 1 + n);
	ld ans = (res+min(n*k,m))/n;
	res -= A[1];
	forn(i, min(m,n-1)) {
		ld res1 = res;
		res1 += min(m - i, (n - i) * k);
		res1 /= (n - i);
		ans = max(ans, res1);
		res -= A[i+1];
	}
	cout << fixed<<setprecision(11)<<ans << endl;
	
}
// (a+k)%(b+k)
// a-b*x;