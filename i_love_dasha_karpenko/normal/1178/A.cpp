#include <bits/stdc++.h>

using namespace std;
#define DIM 5007
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

ll n,res = 0,ares = 0;
queue<ll> ans;
int main()
{
	schnell;
	cin >> n;
	ll x, al;
	forn(i, n) {
		cin >> x;
		if (i == 1) {
			al = x;
			ans.push(i);
			ares += x;
		}
		else if (x * 2 <= al) {
			ans.push(i);
			ares += x;
		}
		res += x;
	}
	if (ares * 2 > res) {
		cout << ans.size() << endl;
		while (!ans.empty()) {
			cout << ans.front() << ' ';
			ans.pop();
		}
	}
	else {
		cout << 0;
	}
	cout << endl;
	return 0;
}
// (a+k)%(b+k)
// a-b*x;