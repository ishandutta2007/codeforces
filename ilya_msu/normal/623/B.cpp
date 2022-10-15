#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1001;
//const int M = 10000000;

ll solve(vector<ll> c, ll a, ll b, ll d) {
    int n = c.size();
    ll l = n + 5, r = -1;
    ll res = 0;
    for (ll i = 1; i < n; ++i) {
        if ((c[i] % d != 0) && ((c[i] + 1) % d != 0) && ((c[i] - 1) % d != 0)) {
            l = min(l, i);
            r = max(r, i);
        }
        if (c[i] % d != 0)
            res += b;
    }
    if (r == -1) {
        if (a >= b)
            return res;
        ll ec = 0;
        ll curs = 0;
        for (int i = 1; i < n; ++i) {
            ll x = -a;
            if (c[i] % d != 0)
                x += b;
            curs = max((ll)0, curs + x);
            ec = max(ec, curs);
        }
        return res - ec;
    }
    vector<ll> prSum(n + 1);
    prSum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        ll x = -a;
        if (c[i - 1] % d != 0)
            x += b;
        prSum[i] = prSum[i - 1] + x;
    }
    ll ma = prSum[r + 1];
    for (int i = r + 1; i <= n; ++i) {
        ma = max(ma, prSum[i]);
    }
    ll mi = prSum[l];
    for (int i = 1; i < l; ++i)
        mi = min(mi, prSum[i]);
    return res - ma + mi;
}

ll solve(vector<ll> c, ll a, ll b) {
    if (c[0] <= 1)
        return LINF;
    vector<ll> di;
    ll x = c[0];
    for (ll d = 2; d * d <= c[0]; ++d) {
        if (x % d == 0) {
            di.push_back(d);
            while (x % d == 0)
                x /= d;            
        }
    }
    if (x != 1)
        di.push_back(x);
    ll res = LINF;
    for (int i = 0; i < di.size(); ++i)
        res = min(res, solve(c, a, b, di[i]));
    return res;
}

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    ll res = solve(c, a, b);
    c[0] += 1;
    res = min(res, solve(c, a, b) + b);
    c[0] -= 2;
    res = min(res, solve(c, a, b) + b);
    c[0] += 1;
    reverse(c.begin(), c.end());
    res = min(res, solve(c, a, b));
    c[0] += 1;
    res = min(res, solve(c, a, b) + b);
    c[0] -= 2;
    res = min(res, solve(c, a, b) + b);
    cout << res << endl;


    
    
}



//#define LOCAL

int main() {
	ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	solve();
#ifdef LOCAL
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}