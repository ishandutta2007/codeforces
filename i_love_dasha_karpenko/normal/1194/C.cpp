#include <bits/stdc++.h>

using namespace std;
#define DIM 107
#define DIM2 400007
#define DIM3 200007
#define INF 10E13
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

ll q;
string s, t, p;
map<char, ll> M;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> q;
	forn(h, q) {
		cin >> s >> t >> p;
		M.clear();
		for (ll i = 0; i < p.length(); i++)M[p[i]]++;

		ll po = 0,flag = 0;
		for (ll i = 0; i < t.length(); i++) {
			if (po<s.length() && t[i] == s[po])po++;
			else if (M[t[i]] > 0) {
				M[t[i]]--;
			}
			else {
				cout << "NO" << endl;
				flag = 1;
				break;
			}
		}
		if (po == s.length() && flag == 0)cout << "YES" << endl;
		else if (flag == 0)cout << "NO" << endl;
	}
}