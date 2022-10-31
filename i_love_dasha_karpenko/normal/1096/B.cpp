#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
#define DIM2 10007
#define MODULO 998244353  
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
	cin >> n;
	cin >> s;
	ll i = 0,r = 0;
	if (s[0] == s[n - 1]) {
		r = 1;
		while (i + 1 < n && s[i] == s[i + 1]) {
			i++; r++;
		}
		ll j = n - 1;
		ll r1 = 1;
		while (j - 1 >= 0 && s[j] == s[j - 1]) {
			j--; r1++;
		}
		
		cout << (r1 + 1) * (r+1) % MODULO  << endl;
		
	}
	else {
		ll res = 0;
		r = 1;
		while (i + 1 < n && s[i] == s[i + 1]) {
			i++; r++;
		}
		res += r;
		r = 1;
		ll j = n - 1;

		while (j - 1 >= 0 && s[j] == s[j - 1]) {
			j--; r++;
		}
		res += r;
		res %= MODULO;
		cout << res+1 << endl;
	}
	return 0;
}