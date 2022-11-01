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
const int maxn = 300500;

int n, m;
int prv[maxn], nxt[maxn];
int df[maxn];

void solve() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        prv[i] = i-1;
        nxt[i] = i+1;
        df[i] = -1;
    }

    forn(i, m) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        --l,--r,--x;
        {
            int p = prv[x];
            while (p >= l) {
                df[p] = x;
                p = prv[p];
            }
            prv[x] = p;
            nxt[p] = x;
        }
        {
            int p = nxt[x];
            while (p <= r) {
                df[p] = x;
                p = nxt[p];
            }
            nxt[x] = p;
            prv[p] = x;
        }
    }
    forn(i, n) printf("%d ", df[i]+1);
    printf("\n");
}


int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    solve();

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}