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
const int maxn = 1000500;

int n, m;
multiset<int> q;
int tk[100], lft[100];

void scan()
{
    scanf("%d%d", &n, &m);
    forn(i, n) {
        int a;
        scanf("%d", &a);
        q.insert(a);
    }
    forn(i, m) {
        int b;
        scanf("%d", &b);
        ++lft[b];
    }
}

int solve()
{
    int res = 0;
    ford(b, 50) while (lft[b]) {
        int x = 1<<b;
        multiset<int>::iterator it = q.lower_bound(x);
        if (it == q.end()) {
            bool ok = false;
            for (int c = 32; c > b; --c) if (tk[c]) {
                ok = true;
                --tk[c];
                q.insert((1<<c) - (1<<b));
                --lft[b];
                ++tk[b];
                break;
            }
            if (!ok) {
                lft[b] = 0;
            }
        }
        else {
            int t = *it - x;
            q.erase(it);
            if (t)
                q.insert(t);
            --lft[b];
            ++tk[b];
            ++res;
        }
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    scan();
    cout << solve() << endl;

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}