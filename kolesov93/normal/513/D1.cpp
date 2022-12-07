#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
const ld PI = acos(-1.);
const int N = 111;

vector<int> lft[N], rght[N];
bool f[N][N];
bool was[N][N];
int best[N][N];

bool rec(int x, int sz) {
    if (was[x][sz]) {
        return f[x][sz];
    }
    was[x][sz] = true;
    bool& ans = f[x][sz];
    ans = false;
    assert(sz);

    if (sz <= 1) {
        if (lft[x].size() == 0 && rght[x].size() == 0) {
            ans = true;
        } else ans = false;
        return ans;
    }
    if (rght[x].size() && rght[x].back() > x + sz - 1) {
        ans = false;
        return ans;
    }

    for (int lsz = 0; lsz < sz; ++lsz) {
        int rsz = sz - 1 - lsz;
        
        bool can = true;
        if (lsz < lft[x].size()) can = false;
        else {
            if (lft[x].size() && lft[x].back() > x + lsz) can = false;
        }
        if (rsz < rght[x].size()) can = false;
        else {
            if (rght[x].size() && rght[x].front() <= x + lsz) can = false;
        }

        if (can) {
            if ((lsz == 0 || rec(x + 1, lsz)) && (rsz == 0 || rec(x + lsz + 1, rsz))) {
                ans = true;
                best[x][sz] = lsz;
                return ans;
            }
        }
    }

    ans = false;
    return ans;
}

void print(int x, int sz) {
    if (sz == 0) {
        return;
    }
    print(x + 1, best[x][sz]);
    cout << x << ' ';
    print(x + 1 + best[x][sz], sz - 1 - best[x][sz]);
}

int main() {
    int n, c;
    cin >> n >> c;
    while (c--) {
        int x, y; string s;
        cin >> x >> y >> s;
        if (x >= y) {
            puts("IMPOSSIBLE");
            return 0;
        }

        if (s == "LEFT") {
            lft[x].push_back(y);
        } else {
            rght[x].push_back(y);
        }
    }
    for (int i = 1; i <= n; ++i) {
        sort(lft[i].begin(), lft[i].end());
        sort(rght[i].begin(), rght[i].end());
        lft[i].resize(unique(lft[i].begin(), lft[i].end()) - lft[i].begin());
        rght[i].resize(unique(rght[i].begin(), rght[i].end()) - rght[i].begin());
        if (lft[i].size() && rght[i].size() && lft[i].back() >= rght[i].front()) {
            puts("IMPOSSIBLE");
            return 0;
        }
    }

    if (rec(1, n)) {
        print(1, n);
        cout << endl;
    } else {
        puts("IMPOSSIBLE");
    }

    return 0;
}