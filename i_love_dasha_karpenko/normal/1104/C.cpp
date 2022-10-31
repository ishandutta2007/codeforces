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

string s;
pp pos1 = { 1,2 }, pos0 = { 1,1 };
int main() {
	schnell;

	cin >> s;
	for (ll i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			cout << pos1.fi << ' ' << pos1.sc << endl;
			pos1.fi++;
			if (pos1.fi > 4)pos1.fi = 1;
		}
		else {
			cout << pos0.fi << ' ' << pos0.sc << endl;
			pos0.fi += 2;
			if (pos0.fi > 4)pos0.fi = 1;
		}
	}
	return 0;
}