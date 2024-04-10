#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 1000 * 1000 * 5;
bitset<maxn> u;

int main()
{
    int n, x;
    cin >> n >> x;
    vi v(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    if (x == 2) {
        printf("0\n");
        return 0;
    }
    if (sz(v) && v[0] == 1) {
        printf("1\n");
        return 0;
    }
    --x;
    if (x >= maxn - 3) {
        printf("-1\n");
        return 0;
    }
    u.flip();
    u[0] = false;
    u[1] = false;
    vi w;
    for (int i = 2; i <= x; ++i) {
        if (!u[i]) continue;
        w.pb(i);
        if (i > maxn / i + 1) continue;
        for (int j = i * i; j <= x; j += i)
            u[j] = false;
    }
    for (int i = 0; i < sz(w); ++i) {
        if (!binary_search(all(v), w[i])) {
            printf("-1\n");
            return 0;
        }
    }
    cout << sz(w) << "\n";
    return 0;
}