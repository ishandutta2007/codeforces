#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <bitset>
#include <random>
#include <memory>
#include <iomanip>

typedef long long ll;
typedef long double ld;

using namespace std;

const int R = 21;
const int TH = 360;

vector<vector<int>> g;

bool bfs(int fr, int to) {
    int n = (int)g.size();
    vector<int> used(n), q(n);
    q[0] = fr, used[fr] = 1;
    for (int l = 0, r = 1; l < r;) {
        int v = q[l++];
        for (int i : g[v]) {
            if (!used[i]) {
                used[i] = 1;
                q[r++] = i;
            }
        }
    }
    return used[to];
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> w(R + 1, vector<int>(TH));
    vector<vector<int>> l(R, vector<int>(TH));
    while (n--) {
        char t;
        cin >> t;
        if (t == 'C') {
            int r, a, b;
            cin >> r >> a >> b;
            while (a != b) {
                w[r][a++] = 1;
                if (a == 360) a = 0;
            }
        } else {
            int r1, r2, a;
            cin >> r1 >> r2 >> a;
            for (int i = r1; i < r2; i++) l[i][a] = 1;
        }
    }

    g.assign((R + 2) * TH, {});

    vector<int> p(TH, 1);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < TH; j++) {
            int nxt = (j + 1) % TH;
            if (!l[i][nxt]) {
                g[i * TH + j].push_back(i * TH + nxt);
                g[i * TH + nxt].push_back(i * TH + j);
            }
        }

        for (int j = 0; j < TH; j++) {
            if (!w[i + 1][j]) {
                g[i * TH + j].push_back((i + 1) * TH + j);
                g[(i + 1) * TH + j].push_back(i * TH + j);
            }
        }
    }

    if (bfs(0, R * TH)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int test;
    cin >> test;
    while (test--) solve();


    return 0;
}