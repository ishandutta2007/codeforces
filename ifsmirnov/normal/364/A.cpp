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

int n, a;
char s[maxn];
int b[maxn];

void scan() {
    scanf("%d", &a);
    scanf("%s", s);
    n = strlen(s);
}

void solve() {
    i64 res = 0;
    forn(i, n) {
        int q = 0;
        for (int j = i; j < n; ++j) {
            q += s[j]-'0';
            ++b[q];
        }
    }

    if (a == 0) {
        i64 t = (i64) n * (n+1) / 2;
        cout << (i64)b[0] * t * 2  - (i64)b[0]*b[0] << endl;
        return;
    }

    for (int i = 1; i <= min(a, 40040); ++i) if (a%i == 0 && a/i < 50000) {
        res += (i64)b[i] * b[a/i];
    }

    cout << res << endl;
}

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}