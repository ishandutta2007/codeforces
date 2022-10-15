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
const ll mod = 1000000007;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    for (int i = 0; i < n; ++i)
        cin >> maze[i];
    vector<vector<ll> > dh(n, vector<ll>(m, 0)), dv(n, vector<ll>(m, 0));
    vector<vector<ll> > fh(n, vector<ll>(m, 0)), fv(n, vector<ll>(m, 0));
    vector<vector<ll> > stidh(n, vector<ll>(m, 0)), stidv(n, vector<ll>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = m - 2; j >= 0; --j) {
            fh[i][j] = fh[i][j + 1] + (maze[i][j + 1] == '.');
        }

    }
    for (int j = 0; j < m; ++j) {
        for (int i = n - 2; i >= 0; --i) {
            fv[i][j] = fv[i + 1][j] + (maze[i + 1][j] == '.');
        }
    }
    for (int i = 0; i < n; ++i) {
        int st = 0;
        stidh[i][0] = st;
        int r = 0;
        for (int j = 1; j < m; ++j) {
            r += (maze[i][j] == 'R');
            int f = fh[i][j];
            while (r > f) {
                ++st;
                if (maze[i][st] == 'R')
                    --r;

            }
            stidh[i][j] = st;
        }
    }

    for (int j = 0; j < m; ++j) {
        int st = 0;
        stidv[0][j] = st;
        int r = 0;
        for (int i = 1; i < n; ++i) {
            r += (maze[i][j] == 'R');
            int f = fv[i][j];
            while (r > f) {
                ++st;
                if (maze[st][j] == 'R')
                    --r;

            }
            stidv[i][j] = st;
        }
    }

    dh[0][0] = dv[0][0] = 1;
    vector<ll> addh(n, 0), addv(m, 0);
    vector<ll> addsth(n, 0), addstv(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            while (addsth[i] < stidh[i][j]) {
                addh[i] -= dv[i][addsth[i]];
                ++addsth[i];
            }
            dh[i][j] += addh[i];
            dh[i][j] %= mod;
            while (addstv[j] < stidv[i][j]) {
                addv[j] -= dh[addstv[j]][j];
                ++addstv[j];
            }
            dv[i][j] += addv[j];
            dv[i][j] %= mod;
            addh[i] += dv[i][j];
            addv[j] += dh[i][j];

        }
    }
    if ((n == 1) || (m == 1)) {
        int r = 0;
        for (int i = 0; i < maze.size(); ++i) {
            for (int j = 0; j < m; ++j) {
                if (maze[i][j] == 'R')
                    ++r;
            }
        }
        if (r > 0)
            cout << 0 << endl;
        else 
            cout << 1 << endl;
        return;

    }
    cout << (dv[n - 1][m - 1] + dh[n - 1][m - 1]) % mod << endl;

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}