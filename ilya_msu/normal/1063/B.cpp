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

bool ok(pii v, int m, int n) {
    return (v.first >= 0) && (v.second >= 0) && (v.first < m) && (v.second < n);
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void solve() {
    int m, n;
    cin >> m >> n;
    int r, c;
    cin >> r >> c;
    --r, --c;
    int x, y;
    cin >> x >> y;
    vector<string> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    vector<vector<int> > d(m, vector<int> (n, -1));
    
    d[r][c] = 0;
    
    deque<pii> q;
    q.push_back(pii(r, c));
    while (!q.empty()) {
        pii v = q.front();
        q.pop_front();
        for (int i = 0; i < 4; ++i) {
            pii w(v.first + dy[i], v.second + dx[i]);
            if (ok(w, m, n) && (d[w.first][w.second] == -1) && (a[w.first][w.second] != '*')) {
                if (i < 2) {
                    d[w.first][w.second] = d[v.first][v.second];
                    q.push_front(w);
                }
                else {
                    d[w.first][w.second] = d[v.first][v.second] + 1;
                    q.push_back(w);
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][j] == -1)
                continue;
            int l = (c - j + d[i][j]) / 2;
            int r = (j - c + d[i][j]) / 2;
            if ((l <= x) && (r <= y))
                ++res;
        }
    }
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