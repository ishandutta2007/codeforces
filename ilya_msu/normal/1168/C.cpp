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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> last(19, n);
    vector<vector<int> > clos(n, vector<int>(19, n));
    for (int i = n - 1; i >= 0; --i) {
        vector<int> mv;
        for (int j = 0; j < 19; ++j) {
            if ((a[i] >> j) & 1) {
                mv.push_back(last[j]);
                last[j] = i;
                clos[i][j] = i;
            }
        }
        for (int j = 0; j < mv.size(); ++j) {
            int id = mv[j];
            if (id == n)
                continue;
            for (int k = 0; k < 19; ++k) {
                clos[i][k] = min(clos[i][k], clos[id][k]);
            }
        }
    }
    int x, y;
    for (int qq = 0; qq < q; ++qq) {
        cin >> x >> y;
        --x, --y;
        int ok = 0;
        for (int i = 0; i < 19; ++i) {
            if (((a[y] >> i) & 1) && (clos[x][i] <= y))
                ok = 1;
        }
        if (ok)
            cout << "Shi\n";
        else 
            cout << "Fou\n";
    }

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
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