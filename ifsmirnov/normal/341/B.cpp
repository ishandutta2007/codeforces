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

int n;
int a[maxn];

int b[maxn];
int ml = 0;

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
}

void solve() {
    forn(i, n+5) b[i] = 1000000000;
    b[0] = 0;
    forn(i, n) {
        int p = upper_bound(b, b+n+1, a[i]) - b - 1;
//         cout << p << endl;
        if (p == ml) ++ml;
        b[p+1] = min(b[p+1], a[i]);
    }
    cout << ml << endl;
}

int main()
{
    scan();
    solve();

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}