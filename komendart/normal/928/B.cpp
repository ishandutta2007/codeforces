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
const int maxn = (int)1e5 + 5;
const dbl pi = acos(-1);

int n, k, a[maxn], d[maxn];

int main() {
//    fin("t.in");
    sync;
    cin >> n >> k;
    E(i, 1, n) {
    	cin >> a[i];
    }
    E(i, 1, n) {
    	if (a[i] == 0) {
    		d[i] = 1 + min(i - 1, k) + min(n - i, k);
    		cout << d[i] << " ";
    		cont;
    	}
    	int l = max(i - k, 1);
    	int r = min(i + k, n);
    	int x = a[i];
    	l = min(max(l, x + k + 1), n + 1);
    	d[i] = d[x] + (r - l + 1);
    	cout << d[i] << " ";
    }
    return 0;
}