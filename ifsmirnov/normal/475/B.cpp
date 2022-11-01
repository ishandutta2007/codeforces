#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

const int maxn = 25;
int n, m;
int b[maxn][maxn];
int dx[maxn], dy[maxn];

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || b[x][y]) return;
    b[x][y] = 1;
    dfs(x, y+dx[x]);
    dfs(x+dy[y], y);
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;
    string s;
    cin >> s;
    forn(i, n) dx[i] = s[i] == '>'?1:-1;
    cin >> s;
    forn(i, m) dy[i] = s[i] == 'v'?1:-1;
    dfs(0, 0);
    forn(i, n) forn(j, m) if (!b[i][j]) goto fail;
    forn(i, n) forn(j, m) b[i][j] = 0;
    forn(i, n) dx[i] *= -1;
    forn(j, m) dy[j] *= -1;
    dfs(0, 0);
    forn(i, n) forn(j, m) if (!b[i][j]) goto fail;
    cout << "YES" << endl;
    return 0;
    fail: cout << "NO" << endl;


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}