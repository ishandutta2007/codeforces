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

const int maxn = 1000 * 1000;

int a[maxn * 4];
int h;

void put(int x, int y)
{
    x += h - 1;
    a[x] = y;
    x /= 2;
    while (x) {
        a[x] = max(a[x * 2] , a[x * 2 + 1]);
        x /= 2;
    }
}

int get(int l, int r)
{
    l += h - 1, r += h - 1;
    if (l > r) return 0;
    if (l == r) return a[l];
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
    h = 1;
    while (h < maxn) h *= 2;
    memset(a, 0, sizeof(a));
    int n;
    cin >> n;
    vector<ii> v(n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        --x;
        v[x].first = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        --x;
        v[x].second = n - i;
    }
    sort(all(v));
    int res = 0;
    for (int i = 0; i < sz(v); ++i) {
        int cur = 1 + get(1, v[i].second);
        res = max(res, cur);
        put(v[i].second, cur);
    }
    cout << res << "\n";
    return 0;
}