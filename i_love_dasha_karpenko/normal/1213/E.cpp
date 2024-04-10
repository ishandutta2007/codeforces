#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
#define DIM2 DIM*150
#define MODULO 998244353 
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const ll INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
const ld eps = 0.0000001;
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
ll n;
string s, t;
ll Check(string x) {
	return (x != s && x != t);
}
ll Rc(string x) {
	return (x == s || x == t);
}
int main() {
	schnell;
	cin >> n;
	cin >> s >> t;
	cout << "YES\n";
	if (Rc("aa")) {
		if (Rc("bb") || Rc("cc"))forn(i, n)cout << "abc";
		else {
			if (Rc("ab") || Rc("bc") || Rc("ca"))forn(i, n)cout << "acb";
			else forn(i, n)cout << "abc";
		}
		cout << endl;
		return 0;
	}
	if (Rc("bb")) {
		if (Rc("aa") || Rc("cc"))forn(i, n)cout << "abc";
		else {
			if (Rc("ab") || Rc("bc") || Rc("ca"))forn(i, n)cout << "acb";
			else forn(i, n)cout << "abc";
		}
		cout << endl;
		return 0;
	}
	if (Rc("cc")) {
		if (Rc("bb") || Rc("aa"))forn(i, n)cout << "abc";
		else {
			if (Rc("ab") || Rc("bc") || Rc("ca"))forn(i, n)cout << "acb";
			else forn(i, n)cout << "abc";
		}
		cout << endl;
		return 0;
	}

	if (Check("ab") && Check("bc")) {
		//cout << "YES\n";
		forn(i, n)cout << 'a';
		forn(i, n)cout << 'b';
		forn(i, n)cout << 'c';
		cout << endl;
		return 0;
	}
	if (Check("ac") && Check("cb")) {
		//cout << "YES\n";
		forn(i, n)cout << 'a';
		forn(i, n) cout << 'c';
		forn(i, n) cout << 'b';

		cout << endl;
		return 0;
	}
	if (Check("ba") && Check("ac")) {
		//cout << "YES\n";
		forn(i, n) cout << 'b';
		forn(i, n) cout << 'a';
		forn(i, n) cout << 'c';
		cout << endl;
		return 0;
	}
	if (Check("bc") && Check("ca")) {
		//cout << "YES\n";
		forn(i, n) cout << 'b';
		forn(i, n) cout << 'c';
		forn(i, n) cout << 'a';

		cout << endl;
		return 0;
	}
	if (Check("ca") && Check("ab")) {
		//cout << "YES\n";
		forn(i, n) cout << 'c';
		forn(i, n) cout << 'a';
		forn(i, n) cout << 'b';
		cout << endl;
		return 0;
	}
	if (Check("cb") && Check("ba")) {
		//cout << "YES\n";
		forn(i, n) cout << 'c';
		forn(i, n) cout << 'b';
		forn(i, n) cout << 'a';
		cout << endl;
		return 0;
	}
	while (1);
	return 0;
}