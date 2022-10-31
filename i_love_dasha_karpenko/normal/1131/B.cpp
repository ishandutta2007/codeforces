#include <bits/stdc++.h>

using namespace std;
#define DIM 10007
#define DIM2 400007
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
ll n;
pll A[DIM];
int main()
{
	schnell;
	cin >> n;
	
	forn(i, n) {
		cin >> A[i].fi >> A[i].sc;
	}
	ll res = 0;
	A[0] = { 0,0 };
	fore(0,i, n - 1) {
		//if (i!=0 && A[i] == A[i + 1])continue;
		if (i == 0 || A[i].first > A[i].sc) {
			if (A[i + 1].sc >= A[i].fi) {
				res += min(A[i + 1].first, A[i + 1].sc) - A[i].fi + 1;
			}
		}
		else if (A[i].sc>A[i].first){
			if (A[i + 1].fi >= A[i].sc) {
				res += min(A[i + 1].first, A[i + 1].sc) - A[i].sc + 1;
			}
		}
		else {
			
			res += min(A[i + 1].first, A[i + 1].sc) - A[i].sc ;
			
		}
	}
	cout << res << endl;
}
// 1 1 1 1 1 1 1 1
// 8 4
//   A      A