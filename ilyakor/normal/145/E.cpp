#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int h = 1 << 20;

int a[2 * h + 1][3];
int sg[2 * h + 1];

string s;

void init(int v, int L, int R, int l, int r) {
    if (R < l || L > r) return;
    if (L == R) {
        int val = s[L] == '4' ? 1 : -1;
        a[v][0] = max(val, 0);
        a[v][1] = min(val, 0);
        a[v][2] = val;
        return;
    }

    int m = (L + R) / 2;
    init(2 * v + 1, L, m, l, r);
    init(2 * v + 2, m + 1, R, l, r);

    a[v][2] = a[2 * v + 1][2] + a[2 * v + 2][2];
    a[v][0] = max(a[2 * v + 1][0], a[2 * v + 1][2] + a[2 * v + 2][0]);
    a[v][1] = min(a[2 * v + 1][1], a[2 * v + 1][2] + a[2 * v + 2][1]);
}

void neg(int v, int L, int R, int l, int r) {
    if (R < l || L > r) return;
    if (l <= L && R <= r) {
        sg[v] *= -1;
        int x0 = -a[v][1];
        int x1 = -a[v][0] ;
        int x2 = -a[v][2];
        a[v][0] = max(0, x0);
        a[v][1] = min(0, x1);
        a[v][2] = x2;
        return;
    }

    int m = (L + R) / 2;
    neg(2 * v + 1, L, m, l, r);
    neg(2 * v + 2, m + 1, R, l, r);

    a[v][2] = a[2 * v + 1][2] + a[2 * v + 2][2];
    a[v][0] = max(a[2 * v + 1][0], a[2 * v + 1][2] + a[2 * v + 2][0]);
    a[v][1] = min(a[2 * v + 1][1], a[2 * v + 1][2] + a[2 * v + 2][1]);

    if (sg[v] == -1) {
        int x0 = -a[v][1];
        int x1 = -a[v][0] ;
        int x2 = -a[v][2];
        a[v][0] = max(0, x0);
        a[v][1] = min(0, x1);
        a[v][2] = x2;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 2 * h; ++i)
        sg[i] = 1;

    cin >> s;
    init(0, 0, h - 1, 0, sz(s) - 1);


    for (int i = 0; i < m; ++i) {
        string q;
        cin >> q;
        if (q == "switch") {
            int l, r;
            cin >> l >> r;
            --l, --r;
            neg(0, 0, h - 1, l, r);
        } else {
            int cnt1 = (-a[0][2] + n) / 2;
            int mx = a[0][0];
            int res = cnt1 + mx;
            printf("%d\n", res);
        }
    }
    return 0;
}