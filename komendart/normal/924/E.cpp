#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define fin(name) freopen(name, "r", stdin)
#define fout(name) freopen(name, "w", stdout)
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)1e9 + 7;
const dbl eps = (dbl)1e-8;
const int maxn = (int)2e4 + 5;
const dbl pi = acos(-1);

int ans = 0;
int n, l, r;
pii a[maxn];
vector <int> v0, v1;
int d[maxn];

void prodv(int& u, int& sumh, int h, int gr, int dop = 0) {
	if (h < 0 || u > gr + 1)
		return;
	while (sumh <= h && u <= gr) {
		sumh += a[v1[u]].X;
		++u;
	}
	if (sumh <= h)
		ans = max(ans, u + dop);
	else
		ans = max(ans, u);
}

int main() {
//    fin("t.in");
    sync;
    cin >> n >> l >> r;
    F(i, 0, n) {
    	cin >> a[i].X;
    }
    F(i, 0, n) {
    	cin >> a[i].Y;
    }
    sort(a, a + n);
    F(i, 0, n) {
    	if (a[i].Y == 0)
    		v0.pb(i);
    	else
    		v1.pb(i);
    }
    int u0 = 0;
    int sum0 = 0;
    int u1 = 0;
    int sum1 = 0;
   	E(i, 0, r)
		d[i] = inf;
	d[0] = 0;
	I(i, v0) {
		DF(j, r, 0) {
			if (d[j] == inf)
				cont;
			d[j + a[i].X] = 0;
		}
	}
	int minl = r + 1;
	int minl2 = r + 1;
	E(i, l, r)
		if (d[i] != inf) {
			minl = i;
			break;
		}
	DF(i1, sz(v1) - 1, 0) {
		int i = v1[i1];
		E(j, l, r) {
			if (d[j] != inf) {
				minl = j;
				break;
			}
		}
		E(j, minl, r) {
			if (d[j] != inf && d[j] < sz(v1) - i1 - 1) {
				minl2 = j;
				break;
			}
		}
		prodv(u0, sum0, r - minl, i1);
		prodv(u1, sum1, r - minl2, i1, 1);

		DF(j, r, 0) {
			if (d[j] == inf)
				cont;
			d[j + a[i].X] = min(d[j + a[i].X], d[j] + 1);
		}
//		cout << i << " " << a[i].X << " " << d[0] << " " << d[3] << endl;
	}
//	exit(0);
	E(j, l, r) {
		if (d[j] != -1 && d[j] < sz(v1)) {
			minl2 = j;
			break;
		}

	}
	/*
	cout << minl2 << endl;
	cout << sum1 << endl;
	cout << u1 << endl;
	cout << r - minl2 << endl;
	*/
	prodv(u1, sum1, r - minl2, -1, 1);
	cout << ans << endl;
    return 0;
}