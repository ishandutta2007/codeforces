#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;

const int maxn = 1000500;

int n, q;
int res[maxn];

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);
    int pos[2] = {0, 1};

    forn(i, q) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int d;
            scanf("%d", &d);
            forn(j, 2) pos[j] = (pos[j] + d + n) % n;
        } else {
            forn(j, 2) pos[j] ^= 1;
        }
    }

//     cout << pos[0] << " " << pos[1] << endl;
    forn(i, n/2) {
        res[(pos[0] + i*2)%n] = i*2;
        res[(pos[1] + i*2)%n] = i*2+1;
    }

    forn(i, n) printf("%d ", res[i] + 1);
    printf("\n");

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}