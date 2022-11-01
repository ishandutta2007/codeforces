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

int cnt[10];
int l[10], r[10];
int n, m;

void scan() {
    scanf("%d", &n);
    forn(i, n) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
        m += x;
    }
}

int intersect(int a, int b, int c, int d) {
    return max(0, min(b, d) - max(a, c));
}

int solve(int lq, int rq, int d) {
//     cout << d << ": " << lq << " " << rq << endl;
    int cnt = 0;
    forn(i, 5) {
        cnt += intersect(lq, rq, l[i], r[i]) * abs(i-d);
    }
    return cnt;
}

void solve() {
    if (m < 3) {
        cout << -1 << endl;
        return;
    }

    ford(i, 5) {
        if (i == 4) {
            l[i] = 0;
        } else {
            l[i] = r[i+1];
        }
        r[i] = l[i] + cnt[i];
//         cerr << i << ": " << l[i] << " " << r[i] << endl;
    }

    int mn = 1000000000;
    for (int n4 = 0; n4*4 <= m; ++n4) if ((m-n4*4)%3 == 0) {
        int n3 = (m-n4*4)/3;
//         cout << "n4 = " << n4 << ", n3 = " << n3 << endl;
        int d4 = solve(0, n4, 4);
        int d3 = solve(n4, n4+n3, 3);
        int d0 = solve(n4+n3, n, 0);
        mn = min(mn, d4+d3+d0);
    }
    if (mn == 1000000000) {
        cout << -1 << endl;
    } else {
        cout << mn/2 << endl;
    }
}

int main()
{
//     freopen("input.txt", "r", stdin);

    scan();
    solve();

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}