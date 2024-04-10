#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eq(x, y) (abs((x)-(y))<eps)
#define lt(x, y) ((x)<(y)-eps)
#define le(x, y) ((x)<=(y)+eps)
#define gt(x, y) ((x)>(y)+eps)
#define ge(x, y) ((x)>=(y)-eps)
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9+100500;
const int maxn = 1<<21;

int precalc[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8,
7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};

/*
map<int, int> gr;
int go(int x)
{
    if (gr.count(x)) return gr[x];
    if (x+1 == 1<<n) return gr[x] = 0;
    
    vi t;
    forn(i, n) if (!(x&(1<<i))) {
        int tx = x;
        for (int j = i+1; j <= n; j += i+1)
            tx |= (1<<(j-1));
        t.pb(go(tx));
    }

    sort(all(t));
    t.erase(unique(all(t)), t.end());
    t.pb(1000000);
    forn(i, 100) if (t[i] != i) return gr[x] = i;
    assert(false);
}
int solve(int n)
{
    gr.clear();
    ::n = n;
    int t = go(0);
    return t;
}
*/

set<int> used;

int main()
{
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    int x = 0;
    for (int i = 2; i*i <= n; i++) if (!used.count(i)) {
        int cnt = 0;
        for (i64 j = i; (i64) j <= (i64)n; j *= i) {
            assert(!used.count(j));
            used.insert(j);
            ++cnt;
        }
        x ^= precalc[cnt]; 
    }
    x ^= ((int)(n - used.size()) & 1);

    cout << (x ? "Vasya" : "Petya") << endl;

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}