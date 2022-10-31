#include <bits/stdc++.h>

using namespace std;
#define DIM 100007
#define DIM2 DIM*DIM
#define DIM3 200007
#define INF 10E10
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

typedef long long ll;
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

ll n, A[DIM];
int main()
{
	schnell;
	cin >> n;

	forn(i, n)cin >> A[i];
	sort(A + 1, A + 1 + n);
	ll ro = 0;
	ll res = 0;
	A[0] = -1;
	forn(i, n - 1) {
		if (A[i] == A[i + 1])ro++;
	}
	if (ro >= 2) {
		cout << "cslnb" << endl;
		return 0;
	}
	if (ro == 1) {
		forn(i, n - 1) {
			if (A[i] == A[i + 1] && A[i] - A[i - 1] > 1 && A[i] != 0) {
				A[i]--;
				res++;
				break;
			}
			else if (A[i] == A[i + 1]) {
				cout << "cslnb" << endl;
				return 0;
			}
		}
	}

	res += A[1];
	A[1] = 0;
	fore(2, i, n) {
		res += A[i] - A[i - 1] - 1;
		A[i] = A[i - 1] + 1;
	}
	if (res % 2 == 1) {
		cout << "sjfnb\n";
	}
	else {
		cout << "cslnb" << endl;
	}
}