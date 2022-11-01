#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
const int maxn = 1e5 + 5;
const int inf = 1e8;
const double eps = 1e-8;
const int base = 1073676287;

void read(int& x) {
    scanf("%d", &x);
}
 
void read(int& x, int& y) {
    scanf("%d %d", &x, &y);
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> g[35];

pair<ll, ll> ans[35];

int opp(int x) {
    if (x == 0)
        return 2;
    if (x == 1)
        return 3;
    if (x == 2)
        return 0;
    if (x == 3)
        return 1;
    return -1;
}

void build(int v, int from, ll x, ll y, int st, int p = -1) {
    int dir = 0;
    ans[v] = mp(x, y);

    for (int to:g[v]) {
        if (to == p) continue;
        if (dir == opp(from))
            dir++;
        if (dir >= 4) {
            cout << "NO";
            exit(0);
        }
        ll nx = x + (1LL << st) * dx[dir];
        ll ny = y + (1LL << st) * dy[dir];
        build(to, dir, nx, ny, st - 1, v);
        dir++;
    }
}

int main() {
    int n;
//    freopen("input.txt", "r", stdin);
    read(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        read(u,v );
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    build(0, -1, 0, 0, 40);
    // return 0;
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << ans[i].f << ' ' << ans[i].s << endl;
    return 0;
}