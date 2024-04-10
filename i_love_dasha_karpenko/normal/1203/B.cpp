#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long  ll;
typedef long double ld;
#define DIM 2007
#define DIM2 10007
#define MODULO 1000000007  
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const long long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
const ld eps = 0.0000001;
struct pp {
	ld fi, sc;
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
ll n, q,A[407];
int main() {
	schnell;
	cin >> q;
	forn(e, q) {
		cin >> n;
		forn(i, n*4)cin >> A[i];
		sort(A + 1, A + 1 + n*4);
		ll p1 = 1, p2 = n * 4, space = -1, squares = 0, flag = 0;
		while (p2-p1>=2) {
			if (A[p1] != A[p1 + 1]) {
				flag = 1;
				break;
			}
			if (A[p2] != A[p2 - 1]) {
				flag = 1;
				break;
			}
			if (space == -1) {
				space = A[p1] * A[p2];
			}
			if (space != A[p1] * A[p2]) {
				flag = 1;
				break;
			}
			p1 += 2;
			p2 -= 2;
		}
		if (flag==1) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	return 0;
}