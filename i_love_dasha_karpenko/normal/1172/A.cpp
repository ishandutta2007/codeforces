#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
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
ll n,B[DIM],A[DIM],len = 0,take = 0;

void uplen() {
	while (take<n && B[len + 1] == 1) {
		len++;
		take++;
		B[A[take]] = 1;
	}
	while (B[len + 1] == 1) {
		len++;
	}
}
int main()
{
	schnell;
	cin >> n;
	forn(i, n) {
		ll x; cin >> x;
		B[x] = 1;
	}
	forn(i, n)cin >> A[i];
	ll flag = 0,ls = n;
	for (ll i = n; i >= 1; i--) {
		if (A[i] == 1)break;
		if (A[i - 1] != A[i] - 1) {
			flag = 1;
			break;
		}
		ls--;
	}
	if (flag == 0) {
		ll last = A[n];
		for (ll i = 1; i < ls; i++) {
			if (B[last + 1] == 0) {
				flag = 1;
				break;
			}
			B[A[i]] = 1;
			last++;
		}
		if (flag == 1) {
			cout << ls + n << endl;
		}
		else {
			cout << ls - 1 << endl;
		}
		return 0;
	}
	ll i = 0;
	while (i <= n) {
		uplen();
		if (len == n) {
			cout << i + n << endl;
			return 0;
		}
		take++;
		take = min(n, take);
		B[A[take]] = 1;
		i++;
	}
}