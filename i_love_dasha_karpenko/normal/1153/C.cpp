#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef int ll;
typedef long double ld;
#define DIM 100007
#define DIM2 10007
#define MODULO 10000000000 
#define MAXN 1000000
#define DIM2 31
const long long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
struct pp {
	ll fi, sc;
	bool operator < (const pp& b)const {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool operator > (const pp& b)const {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool operator == (const pp& b)const {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
ll n;
string s;
int main() {
	schnell;
	cin>>n >> s;
	if (n % 2 != 0) {
		cout << ":(" << endl;
		return 0;
	}
	ll res1 = 0, res2 = 0;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '(')res1++;
		if (s[i] == ')')res2++;
	}
	ll add = n / 2 - res2;
	for (ll i = n - 1; i >= 0; i--) {
		if (s[i] == '?' && add > 0) {
			add--;
			s[i] = ')';
		}
		else if (s[i] == '?') {
			s[i] = '(';
			
		}
	}
	res1 = 0, res2 = 0;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '(')res1++;
		else res2++;
		if (res1 < res2) {
			cout << ":(" << endl;
			return 0;
		}
		if (res1 == res2 && i != n - 1) {
			cout << ":(" << endl;
			return 0;
		}
	}
	if (res1 != res2) {
		cout << ":(" << endl;
		return 0;
	}
	cout << s << endl;
	return 0;
}