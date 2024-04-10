#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
const ll BLOCK = 400;
const ll DIM = 200007;
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

ll n, k,A[DIM],ans[DIM],vis[DIM];
vector<pp> V;
ll left(ll x) {
	x--;
	if (x <= 0)x = n;
	return A[x];
}
ll right(ll x) {
	x++;
	if (x > n)x = 1;
	return A[x];
}
int main() {
	schnell;
	cin >> n >> k;
	forn(i, n) {
		char ch; cin >> ch;
		if (ch == 'B')A[i] = 1;
	}
	ll lb = 1, rb = 0;
	forn(i, n) {
		if (left(i) != A[i] && right(i) != A[i])rb++;
		else {
			if (lb <= rb)V.pb({ lb,rb });
			vis[i] = 1;
			lb = i + 1;
			rb = i ;
		}
	}
	if (left(n)!=A[n] && right(n)!=A[n]) {
		V.pb({ lb,rb });
		if (lb == 1 && rb==n) {
			forn(i, n) {
				ll r = A[i] ^ (k % 2);
				if (r == 0)cout << 'W';
				else cout << 'B';
			}
			cout << endl;
			return 0;
		}
	}
	if (A[1] != left(1) && A[1] != right(1) && A[n] != left(n)) {
		V[0] = { V.back().fi,V[0].sc };
		V.pop_back();
	}
	for (pp to : V) {
		ll l = to.fi, r = to.sc, lc = left(l), rc = right(r);
		ll c = 0;
		while (c<k) {
			ll next = l + 1;
			if (next > n)next -= n;
			ll olr = r;
			if (l == r) {
				if (rc == lc)A[l] = lc;
				vis[l] = 1;
				break;
			}
			A[l] = lc; vis[l] = 1; l++;
			if (l > n) l = 1;
			A[r] = rc; vis[r] = 1; r--;
			if (r < 1) r = n;
			c++;
			if (next == olr) {
				break;
			}
		}
	}
	forn(i, n) {
		if (vis[i] == 0 && k % 2 == 1) A[i] = 1 - A[i];
		if (A[i] == 0)cout << 'W';
		else cout << 'B';
	}
	cout << endl;
	return 0;
}