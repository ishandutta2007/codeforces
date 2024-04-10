#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

const int maxn = 2 * 1000 * 1000;

int wh[maxn];

vi va, vb;

bool ok(int l, int r) {
    if (wh[va[l]] == -1 || wh[va[r]] == -1) return false;

    if (l == r) return true;

    int x = wh[va[l]];
    int y = wh[va[(r - 1 + sz(va)) % sz(va)]];
    int z = wh[va[r]];

    if (y >= x) {
        return z > y || z < x;
    } else {
        return z > y && z < x;
    }
}

int main() {
    memset(wh, -1, sizeof(wh));

    int la, lb;
    cin >> la >> lb;
    va.resize(la);
    vb.resize(lb);
    for (int i = 0; i < la; ++i)
        scanf("%d", &va[i]);
    for (int i = 0; i < lb; ++i) {
        scanf("%d", &vb[i]);
        wh[vb[i]] = i;
    }

    int l = 0;
    int r = l;
    int cur = 0;
    int res = 0;
    for (; l < la; ++l, --cur) {
        while (cur < min(la, lb) && ok(l, r)) r = (r + 1) % la, ++cur;
        res = max(res, cur);

        if (cur == 0) ++r, ++cur;
    }

    cout << res << "\n";

    return 0;
}