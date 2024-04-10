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
#include<bitset>
#include<random>




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
ll mod = 2520;

int n;
vector<vector<int> > g, e;
vector<int> k;
vector<vector<int> > res;

void solve() {
    cin >> n;
    e.resize(n);
    k.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        k[i] = ((k[i] % mod) + mod) % mod;
    }
    int m;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        e[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> e[i][j];
            --e[i][j];
        }
    }
    res.assign(n, vector<int>(mod, -1));
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            //cerr << i << " " << j << endl;
            if (res[i][j] != -1) {
                continue;
            }
            vector<pii> pos;
            int v = i, c = j;
            while (res[v][c] == -1) {
                pos.push_back(pii(v, c));
                res[v][c] = 0;
                c = (c + k[v]) % mod;
                v = e[v][c % e[v].size()];
            }
            
            if (res[v][c] != 0) {
                int x = res[v][c];
                for (int id = 0; id < pos.size(); ++id) {
                    res[pos[id].first][pos[id].second] = x;
                }
                continue;
            }
            pii p = pii(v, c);
            int id = 0;
            while (pos[id] != p)
                ++id;
            set<int> vt;
            for (; id < pos.size(); ++id)
                vt.insert(pos[id].first);
            int x = vt.size();
            for (id = 0; id < pos.size(); ++id) {
                res[pos[id].first][pos[id].second] = x;
            }
        }
    }
    int q;
    cin >> q;
    int x, y;
    for (int i = 0; i < q; ++i) {
        cin >> x >> y;
        --x;
        y = ((y % mod) + mod) % mod;
        cout << res[x][y] << "\n";
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