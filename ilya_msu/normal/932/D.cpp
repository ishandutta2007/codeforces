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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;


void solve() {
    vector<int> pr = { 0, 0 };
    vector<ll> w = { INF, 0 };
    vector<int> dep = { 0, 1 };
    int q;
    cin >> q;
    ll last = 0;
    int lg = 20;
    vector<vector<int> > up(2, vector<int>(lg, 0));
    vector<vector<ll> > sm(2, vector<ll>(lg, INF));
    for (int i = 1; i < lg; ++i) {
        sm[0][i] = sm[1][i] = sm[0][i - 1] * 2;
    }
    for (int qq = 0; qq < q; ++qq) {
        ll t, r, x;
        cin >> t >> r >> x;
        r ^= last;
        x ^= last;
        if (t == 1) {
            w.push_back(x);
            int id = w.size() - 1;
            for (int i = lg - 1; i >= 0; --i) {
                if (w[up[r][i]] < x) {
                    r = up[r][i];
                }
            }
            if (w[r] < x)
                r = up[r][0];
            pr.push_back(r);
            up.push_back(vector<int>(lg, 0));
            sm.push_back(vector<ll>(lg, INF));
            up[id][0] = pr[id];
            sm[id][0] = w[pr[id]];
            dep.push_back(dep[pr[id]] + 1);
            for (int i = 1; i < lg; ++i) {
                sm[id][i] = sm[pr[id]][i] - w[up[pr[id]][i]] + w[pr[id]];
            }
            //sm
            for (int i = 1; i < lg; ++i)
                up[id][i] = up[up[id][i - 1]][i - 1];
        }
        else {
            int res = 0;
            if (x < w[r]) {
                cout << 0 << "\n";
                last = 0;
                continue;
            }
            ++res;
            x -= w[r];
            for (int i = lg - 1; (r > 0) && (i >= 0); --i) {
                if (sm[r][i] > x) {
                    continue;
                }
                else {
                    x -= sm[r][i];
                    res += min(dep[r] - 1, (1 << i));
                    r = up[r][i];
                }
            }
            
            cout << res << "\n";
            last = res;
        }

    }
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