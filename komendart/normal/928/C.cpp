#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define fin(name) FILE* aasckmasl=freopen(name, "r", stdin)
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
const int maxn = (int)1e3 + 5;
const dbl pi = acos(-1);

string s[maxn];
int a[maxn];
int n;
map <pair <string, int>, int > num;
vector <pair <string, int> > b1[maxn];
vector <int > b[maxn];
map <string, int> d;


int main() {
//    fin("t.in");
    sync;
    cin >> n;
    F(i, 0, n) {
    	cin >> s[i] >> a[i];
    	num[{s[i], a[i]}] = i;
    	int k;
    	cin >> k;
    	F(j, 0, k) {
    		string s;
    		int a;
    		cin >> s >> a;
    		b1[i].pb(mp(s, a));
    	}
    }
    F(i, 0, n) {
    	F(j, 0, sz(b1[i])) {
    		b[i].pb(num[b1[i][j]]);
    	}
    }
    vector <int> q;
    map <string, int> m;
    m[s[0]] = a[0];
    int l = 0;
    q.pb(0);
    d[s[0]] = 0;
    vector <pair <string, int> > ans;
    while (l < sz(q)) {
    	int x = q[l++];
    	if (m[s[x]] != a[x])
    		cont;
    	if (x != 0)
	    	ans.pb({s[x], a[x]});
    	I(to, b[x]) {
    		if ((!d.count(s[to]) || d[s[to]] == d[s[x]] + 1) && (!m.count(s[to]) || m[s[to]] < a[to])) {
    			m[s[to]] = a[to];
    			d[s[to]] = d[s[x]] + 1;
    			q.pb(to);
    		}
    	}
    }
    cout << sz(ans) << endl;
    sort(all(ans));
    F(i, 0, sz(ans)) {
    	cout << ans[i].X << " " << ans[i].Y << "\n";
    }
    return 0;
}