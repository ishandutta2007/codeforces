#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 57
#define DIM2 DIM*150
#define MODULO 1000000007
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
ll n, m, A[DIM][DIM],V[DIM][DIM];
vector<pp> ans;
bool Check(ll x, ll y) {
	if (A[x][y] == 0 || A[x][y + 1] == 0 || A[x + 1][y] == 0 || A[x + 1][y + 1] == 0)return false;
	return true;
}
void Set(ll x, ll y) {
	ans.pb({ x,y });
	V[x][y] = 1;
	V[x + 1][y] = 1;
	V[x][y + 1] = 1;
	V[x + 1][y + 1] = 1;
}
int main() {
	schnell;
	cin >> n >> m;
	forn(i, n)forn(j, m)cin >> A[i][j];
	forn (i, n) {
		forn(j, m) {
			if (A[i][j] == 1 && V[i][j] == 0) {
				if (!Check(i, j)) {
					cout << -1 << endl;
					return 0;
				}
				else Set(i, j);
			}
			else if (A[i][j] == 1) {
				if (Check(i, j))Set(i, j);
			}
		}
	}
	cout << ans.size() << endl;
	for (pp to : ans) {
		cout << to.fi << ' ' << to.sc << endl;
	}
	return 0;
}