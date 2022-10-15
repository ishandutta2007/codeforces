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
    int n;
    cin >> n;
    vector<vector<int> > f(n, vector<int> (n, 0));
    int a, b;
    cin >> a >> b;
    --a, --b;
    for (int i = 0; i < n; ++i) {
        f[i][b] = 1;
        f[a][i] = 1;
        int bb = i + b - a;
        if ((bb >= 0) && (bb < n))
            f[i][bb] = 1;
        bb = -i + a + b;
        if ((bb >= 0) && (bb < n))
            f[i][bb] = 1;
    }
    cin >> a >> b;
    --a, --b;
    queue<pii> q;
    q.push(pii(a, b));
    pii c;
    cin >> c.first >> c.second;
    --c.first, --c.second;
    f[a][b] = 1;
    while (!q.empty()) {
        pii v = q.front();
        q.pop();
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                int x = i + v.first;
                int y = j + v.second;
                if ((x < 0) || (y < 0) || (x >= n) || (y >= n))
                    continue;
                if (f[x][y])
                    continue;
                if (pii(x, y) == c) {
                    cout << "YES\n";
                    return;
                }
                q.push(pii(x, y));
                f[x][y] = 1;
            }
        }
    }
    cout << "NO\n";

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