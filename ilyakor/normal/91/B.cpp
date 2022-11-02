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

const int h = 1 << 19;

int a[h * 2 + 1];

void put(int x, int y) {
    x += h;
    while (x)
        a[x] = max(a[x], y), x /= 2;
}

int get(int l, int r) {
    if (l > r) return 0;
    l += h, r += h;
    int al = a[l], ar = a[r];
    while (l < r - 1) {
        if (l % 2 == 0)
            al = max(al, a[l + 1]);
        if (r % 2 == 1)
            ar = max(ar, a[r - 1]);
        l /= 2, r /= 2;
    }
    return max(al, ar);
}

int main()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    vi vx = v;
    sort(all(vx));
    vx.erase(unique(all(vx)), vx.end());
    for (int i = 0; i < n; ++i)
        v[i] = lower_bound(all(vx), v[i]) - vx.begin();
    vi res(sz(v), -1);
    for (int i = sz(v) - 1; i >= 0; --i) {
        int x = get(0, v[i] - 1) - 1;
        if (x == -1) res[i] = -1;
        else res[i] = x - i - 1;
        put(v[i], i + 1);
    }
    for (int i = 0; i < sz(res); ++i)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}