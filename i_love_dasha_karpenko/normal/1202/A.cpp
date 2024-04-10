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
struct node {
	ll fi, sc, th;
};
ll t;
int main() {
	schnell;
	cin >> t;
	forn(h, t) {
		string s1, s2;
		cin >> s1 >> s2;
		ll pos1 = s1.length() - 1, pos2 = s2.length() - 1;
		while (pos1 >= 0 && pos2 >= 0) {
			if (s2[pos2] == '1')break;
			pos2--;
			pos1--;
		}
		if (s2[pos2] != '1') {
			cout << 0 << endl;
			continue;
		}
		ll r = 0;
		while (pos1 >= 0) {
			if (s1[pos1] == '1')break;
			r++;
			pos1--;
		}
		cout << r << endl;
	}
	return 0;
}