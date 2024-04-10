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

i64 gcd(i64 a, i64 b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int n;
int a[maxn];
i64 res[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d",&a[i]);
    sort(a, a+n);
}

void solve() {
    res[0] = 0;
    forn(i, n) if (i) {
        res[i] = res[i-1] + (i64)(a[i]-a[i-1])*i;
    }
    i64 s = 0;
    forn(i, n) s += res[i];
    s *= 2ll;
    forn(i, n) s += a[i];
    i64 g = gcd(s, n);
    cout << s/g << " " << n/g << endl;
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