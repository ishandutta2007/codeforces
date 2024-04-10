#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define se second
#define fi first
#define mp make_pair
#define left sdfds
#define pb push_back
#define op operator
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef double ld;
const int maxn = 1050;

struct Fen {
    i64 fen[maxn][maxn];
    Fen() {
        memset(fen, 0, sizeof fen);
    }
    void add(int i, int J, i64 x) {
        for (; i < maxn; i |= (i+1)) {
            int j = J;
            for (; j < maxn; j |= (j+1))
                fen[i][j] ^= x;
        }
    }
    i64 get(int i, int J) {
        i64 s = 0;
        for (; i >= 0; i = (i&(i+1))-1) {
            int j = J;
            for (; j >= 0; j = (j&(j+1))-1)
                s ^= fen[i][j];
        }
        return s;
    }

    void add(int i1, int j1, int i2, int j2, i64 x) {
        add(i2, j2, x);
        if (i1) add(i1-1, j2, x);
        if (j1) add(i2, j1-1, x);
        if (i1&&j1) add(i1-1, j1-1, x);
    }
    i64 get(int i1, int j1, int i2, int j2) {
        i64 s = 0;
        s ^= get(i2, j2);
        if (i1) s ^= get(i1-1, j2);
        if (j1) s ^= get(i2, j1-1);
        if (i1&&j1) s ^= get(i1-1, j1-1);
        return s;
    }
};

Fen inner;
Fen all;
Fen top;
Fen left;
int n, m;

void add(int i, int j, i64 x) {
    all.add(i, j, x);
    int fi = i+1, fj = j+1;
    if ((fi*fj)%2 == 1)
        inner.add(i, j, x);
    if (fi%2 == 1)
        top.add(i, j, x);
    if (fj%2 == 1)
        left.add(i, j, x);
}
void add(int i1, int j1, int i2, int j2, i64 x) {
    add(i2, j2, x);
    if (i1) add(i1-1, j2, x);
    if (j1) add(i2, j1-1, x);
    if (i1&&j1) add(i1-1, j1-1, x);
}

i64 get(int i, int j) {
    i64 res = 0;
    int fi = i+1, fj = j+1;
    if ((fi*fj)%2 == 1)
        res ^= all.get(i+1, j+1, n, n);
    if (fj%2 == 1)
        res ^= top.get(0, j+1, i, n);
    if (fi%2 == 1)
        res ^= left.get(i+1, 0, n, j);
    res ^= inner.get(i, j);
    return res;
}
i64 get(int i1, int j1, int i2, int j2) {
    i64 s = 0;
    s ^= get(i2, j2);
    if (i1) s ^= get(i1-1, j2);
    if (j1) s ^= get(i2, j1-1);
    if (i1&&j1) s ^= get(i1-1, j1-1);
    return s;
}

void solve() {
    scanf("%d%d", &n, &m);
//     n = 1000;
//     m = 100000;
//     int s = 0;
    forn(i, m) {
        int t, i1, j1, i2, j2;
        scanf("%d%d%d%d%d", &t, &i1, &j1, &i2, &j2);
//         t = rand()%2+1;
//         i1=rand()%1000;
//         i2=rand()%1000;
//         j1=rand()%1000;
//         j2=rand()%1000;
//         if (i1>i2) swap(i1, i2);
//         if (j1>j2) swap(j1, j2);
        --i1, --j1, --i2, --j2;
        if (t == 2) {
            i64 x;
            scanf("%I64d", &x);
//             x = rand();
            add(i1, j1, i2, j2, x);
        } else {
            printf("%I64d\n", get(i1, j1, i2, j2));
//             s += get(i1, j1, i2, j2);
        }
    }
}


int main()
{
//     freopen("input.txt", "r", stdin);
    solve();

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}