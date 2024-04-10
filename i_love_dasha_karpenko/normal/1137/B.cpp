#include <bits/stdc++.h>

using namespace std;
#define DIM 500007
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

typedef  int ll;
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

string s, t;
ll kmp[DIM],pref[2][DIM];
int main()
{
	schnell;
	cin >> s >> t;
	ll res1 = 0, res0 = 0;
	fore(0, i, s.length() - 1) {
		if (s[i] == '1')res1++;
		else {
			res0++;
		}
	}
	ll val;
	if (t.length() > 1) {
		for (ll i = 1; i < t.length(); i++) {
			ll j = kmp[i - 1];
			while (j > 0 && t[i] != t[j]) {
				j = kmp[j - 1];
			}
			if (t[i] == t[j])j++;
			kmp[i] = j;

		}
		val = kmp[t.length() - 1];
	}
	else val = 0;
	for (ll i = 0; i < t.length(); i++) {
		if (i > 0) {
			pref[1][i] = pref[1][i - 1];
			pref[0][i] = pref[0][i - 1];
		}
		if (t[i] == '0')pref[0][i]++;
		else pref[1][i]++;
	}
	pll start ={ pref[0][t.length() - 1], pref[1][t.length() - 1]};
	ll res = 0;
	if (start.first <= res0 && start.sc <= res1) {
		res0 -= start.first; res1 -= start.sc;
		res++;

		ll r0, r1;
		if (val == 0) {
			r0 = pref[0][t.length() - 1];
			r1 = pref[1][t.length() - 1];
		}
		else {
			r0 = pref[0][t.length() - 1] - pref[0][val - 1];
			r1 = pref[1][t.length() - 1] - pref[1][val - 1];
		}
		while (res1 >= r1 && res0 >= r0) {
			res1 -= r1; res0 -= r0;
			res++;
		}
		if (res >= 1) {
			cout << t;
			res--;
		}
		if (res > 0) {
			string sr = "";
			for (ll i = val; i < t.length(); i++)sr += t[i];
			while (res > 0) {
				cout << sr;
				res--;
			}
		}
		forn(i, res0)cout << '0';
		forn(i, res1)cout << '1';
		cout << endl;
	}
	else cout << s << endl;
	return 0;
}
// (a+k)%(b+k)
// a-b*x;