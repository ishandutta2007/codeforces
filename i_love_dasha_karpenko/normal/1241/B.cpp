#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long  ll;
typedef long double ld;
#define DIM 100007
const ll MOD = 1000000007;
const ll MAXN = 10E18;
const ll INF = 10E16;
const ll masksz = po(20);
const ll bufsize = 500;
struct pp {
	ll fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
bool const operator>(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc > b.sc;
	return a.fi > b.fi;
}


int main() {
	schnell;	
	ll q;
	cin >> q;

	forn(trrte, q) {
		string s, t;
		cin >> s >> t;
		set<char> S;
		ll flag = 0;
		for (ll i = 0; i < s.length(); i++)S.insert(s[i]);
		for (ll i = 0; i < t.length(); i++) {
			if (S.count(t[i]) == 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}