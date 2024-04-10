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

const int maxn = 218 * 1000;

int a[maxn];

const int64 mod = 1000000009LL;

int64 p2[maxn];

int get(int x) {
    if (a[x] == x) return x;
    return a[x] = get(a[x]);
}

void uni(int x, int y) {
    x = get(x), y = get(y);
    if (rand() % 2) swap(x, y);
    a[x] = y;
}

int main()
{
    p2[0] = 1;
    for (int i = 1; i < maxn; ++i)
        p2[i] = (p2[i - 1] * 2LL) % mod;
    for (int i = 0; i < maxn; ++i)
        a[i] = i;
    int n, m;
    cin >> n >> m;
    int k = n;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        if (get(x) != get(y)) {
            --k;
            uni(x, y);
        }
        int res = (int)(p2[(i + 1) - n + k]);
        --res;
        res %= mod;
        res += mod;
        res %= mod;
        printf("%d\n", res);
    }
    return 0;
}