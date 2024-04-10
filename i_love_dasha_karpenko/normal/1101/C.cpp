#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 100007
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
struct node {
	ll fi, sc, pos;
};
ll t, n,ans[DIM];
node A[DIM];
bool mc(node x, node y) {
	return x.fi < y.fi;
}
int main() {
	schnell;
	cin >> t;
	forn(h, t) {
		cin >> n;
		forn(i, n) {
			cin >> A[i].fi >> A[i].sc;
			A[i].pos = i;
			ans[i] = 2;
		}
		sort(A + 1, A + 1 + n,mc);
		ll last = A[1].fi,end = -1;
		
		for (ll i = 1; i <= n; i++) {
			if (A[i].fi <= last) {
				last = max(last, A[i].sc);
				ans[A[i].pos] = 1;
			}
			else {
				end = i;
				break;
			}
		}
		if (end == -1) {
			cout << "-1\n";
		}
		else {
			forn(i, n)cout << ans[i] << ' ';
			cout << '\n';
		}
	}
	return 0;
}