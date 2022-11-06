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
const int maxn = (int)1e5 + 5;
const dbl pi = acos(-1);

bool comp(const pair <pair <ll, ll>, int>& a, const pair <pair <ll, ll>, int>& b) {
	return abs(a.X.X) * abs(b.X.Y) < abs(b.X.X) * abs(a.X.Y);
}

int n;
int t[4 * maxn];
int tadd[maxn];
int pos_in_a1[maxn];
pair <pair <ll, ll>, int> a0[maxn], a1[maxn];
map <pair <ll, ll>, int> mx;
ll x[maxn], v[maxn], w;

int sum(int v, int l, int r, int tl, int tr) {
	if (tl > tr || l > r)
		return 0;
	if (l == tl && r == tr) {
		return t[v];
	}
	int m = (l + r) / 2;
	return sum(2 * v, l, m, tl, min(tr, m)) + sum(2 * v + 1, m + 1, r, max(m + 1, tl), tr);
}

void upd(int v, int l, int r, int pos, int plus) {
	if (l > r || pos < l || pos > r)
		return;
	t[v] += plus;
	if (l == r)
		return;
	int m = (l + r) / 2;
	upd(2 * v, l, m, pos, plus);
	upd(2 * v + 1, m + 1, r, pos, plus);
}

int main() {
//    fin("t.in");
    sync;
    cin >> n >> w;
    F(i, 0, n) {
    	cin >> x[i] >> v[i];
    	a0[i] = {{x[i], v[i] - w}, i};
    	a1[i] = {{x[i], v[i] + w}, i};
    }
    sort(a0, a0 + n, comp);
    sort(a1, a1 + n, comp);
    F(i, 0, n)
    	pos_in_a1[a1[i].Y] = i;
    clean(t);
    ll ans = 0;
    clean(tadd);
    F(i, 0, n) {
    	if (!tadd[i]) {
    		int j = i;
    		while (j < n && !comp(a0[i], a0[j])) {
    			int pos = pos_in_a1[a0[j].Y];
    			upd(1, 0, n - 1, pos, 1);
//    			cout << "upd " << pos << endl;
    			tadd[j] = 1;
    			++j;
    		}
    	}
    	ll x = a0[i].X.X, v = a0[i].X.Y, u = a0[i].Y;
    	int pos = lower_bound(a1, a1 + n, mp(mp(x, v + 2ll * w), (int)u), comp) - a1;
//    	cout << "pos " << pos << endl;
    	ans += sum(1, 0, n - 1, pos, n - 1);
//    	cout << sum(1, 0, n - 1, pos, n - 1) << endl;
    	v += w;
    	ll g = __gcd(abs(x), abs(v));
    	x /= g;
    	v /= g;
    	if (w == 0) {
            if (x < 0) {
                x *= -1ll;
                v *= -1ll;
            }
	    	int plus = ++mx[{x, v}];
	    	ans -= plus;
    	} else {
    		--ans;
    	}
    }
    cout << ans << endl;
    return 0;
}