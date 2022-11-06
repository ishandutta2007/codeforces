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

ll v[maxn], t[maxn];
ll n;

int main() {
//    fin("t.in");
    sync;
    cin >> n;
    F(i, 0, n) {
    	cin >> v[i];
    }
    F(i, 0, n) {
    	cin >> t[i];
    }
    set <pair <ll, int> > q;
    ll qp = 0;
    F(i, 0, n) {
    	ll ans = 0;
    	q.ins({v[i] - qp, i});
    	qp -= t[i];
    	while (sz(q) && q.begin()->X + qp <= 0) {
    		ans += (q.begin()->X + qp + t[i]);
    		q.erase(q.begin());
    	}
    	ans += sz(q) * t[i];
	    cout << ans << " ";
    }
    cout << endl;
    return 0;
}