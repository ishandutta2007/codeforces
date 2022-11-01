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
#define all(x) (x).begin(), (x).end()
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define op operator
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef double ld;
const int maxn = 100500;
const i64 inf = 1e18+100500;

i64 n, l, r, ql, qr;
i64 a[maxn];
i64 ts = 0;

void scan() {
    cin >> n >> l >> r >> ql >> qr;
    forn(i, n) cin >> a[i], ts += a[i];
}

int df(int a, int b) {
    return max(0, max(a, b) - min(a,b) - 1);
}

void solve() {
    i64 mn = inf;
    i64 sl = 0, sr = ts;
    fore(i, 0, n) {
        int cl = i, cr = n-i;
        i64 add;
        if (cl > cr) add = df(cl, cr) * ql;
        else add = df(cl, cr) * qr;
        mn = min(mn, add + (i64)l*sl + (i64)r*sr);

        sl += a[i]; sr -= a[i];
    }
    cout << mn << endl;
}

int main()
{
    ios::sync_with_stdio(false);

//     freopen("input.txt", "r", stdin);

    scan();
    solve();

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}