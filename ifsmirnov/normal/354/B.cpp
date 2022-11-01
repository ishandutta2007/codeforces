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
const int maxn = 24;
const int inf = 10000;

int n;
char s[maxn][maxn];
short d[100][1<<20];

short go(int l, int mask) {
    if (l == n*2 - 2) {
        return 0;
    }
    short& res = d[l][mask];
    if (res == inf) {
        fore(c, 'a', 'z') {
            int nmask = 0;
            forn(i, n) if (mask&(1<<i)) {
                int j = l-i;
                if (i < n-1 && s[i+1][j] == c) {
                    nmask |= 1<<(i+1);
                }
                if (j < n-1 && s[i][j+1] == c) {
                    nmask |= 1<<i;
                }
            }
            if (nmask) {
                int tres = go(l+1, nmask) + (c == 'a') - (c == 'b');
                if (tres > 4000) {
                    continue;
                }
                if (l%2) {
                    if (res == inf || tres > res) {
                        res = tres;
                    }
                } else {
                    if (res == inf || tres < res) {
                        res = tres;
                    }
                }
            }
        }
    }
//     cout << l << " " << mask << ": " << res << endl;
    return res;
}

void solve() {
    forn(i, n*2+1) forn(j, 1<<20) d[i][j] = inf;
    int t = go(0,1) + (s[0][0] == 'a') - (s[0][0] == 'b');
    if (t == 0) {
        cout << "DRAW" << endl;
    } else if (t > 0) {
        cout << "FIRST" << endl;
    } else {
        cout << "SECOND" << endl;
    }
//     cout << t << endl;
}

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%s", s[i]);
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