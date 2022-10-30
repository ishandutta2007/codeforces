#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 300007
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

ll n;
ll A[DIM], flag[2], last[2], fen[DIM],good[2];
void add(ll x, ll pos) {
	for (ll i = pos; i <= n; i += i & -i)fen[i] += x;
}
ll sum(ll pos) {
	ll ret = 0;
	for (ll i = pos; i > 0; i -= i & -i)ret += fen[i];
	return ret;
}
int main() {
	schnell;
	cin >> n;
	forn(i, n) {
		char ch;
		cin >> ch;
		A[i] = ch - 'A';
	}
	ll res = 0, started = 0, prevs = 0;
	A[0] = INF;
	forn(i, n) {
		if (flag[A[i]]) {
			add(1, last[A[i]]);
			ll r= 0;
			if (!flag[A[i] ^ 1])r += sum(last[A[i] ^ 1]);
			res += sum(last[A[i]])-r;
			good[A[i]] = 1;
			if (last[A[i] ^ 1] == i - 1)good[A[i] ^ 1] = 1;
		}
		
		flag[A[i]] = 1;
		last[A[i]] = i;
	}
	cout << res << endl;
	return 0;
}