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

void no() {
	cout << "No" << endl;
	exit(0);
}

void yes() {
	cout << "Yes" << endl;
	exit(0);
}

int n, m;
string a[55];
int tr[55], tc[55];

int main() {
//    fin("t.in");
    sync;
    cin >> n >> m;
    F(i, 0, n) {
    	cin >> a[i];
    }
    clean(tr); clean(tc);
    F(i, 0, n) {
    	if (tr[i])
    		cont;
    	vector <int> cols;
//    	cout << i << endl;
    	F(j, 0, m) {
    		if (a[i][j] == '#')
    			cols.pb(j);
    	}
    	I(x, cols) {
    		if (tc[x]) {
//    			cout << "1 " << x << endl;
    			no();
    		}
    		tc[x] = i + 1;
    	}
    	if (sz(cols) == 0)
    		cont;
    	vector <int> rows;
    	F(j, 0, n) {
    		if (a[j][cols[0]] == '#')
    			rows.pb(j);
    	}
    	I(x, rows) {
    		if (tr[x])
    			no();
    		tr[x] = 1;
    		F(j, 0, m) {
    			if ((a[x][j] == '#') != (tc[j] == i + 1))
    				no();
    		}
    	}
    }
    yes();
    return 0;
}