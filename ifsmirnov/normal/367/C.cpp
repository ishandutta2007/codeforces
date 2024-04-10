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

i64 mn(int k) {
    if (k%2 == 0) return k * (k-1) / 2 + k / 2;
    else return k * (k-1) / 2 + 1;
}
int get(int n) {
    for (int k = 1;; ++k) {
        if (mn(k+1) > n) return k;
    }
}

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    vi s(m);
    forn(i, m) {
        int q;
        scanf("%d%d", &q, &s[i]);
    }
    sort(all(s), greater<int>());
    int t = get(n);
    i64 res = 0;
    forn(i, min(t, m)) res += s[i];

    cout << res << endl;

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}