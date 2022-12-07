#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>
#include <memory.h>
#include <string>
#include <cstring>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld PI = acos(-1.);

inline int prv(int x) {
    return x & (x - 1);
}
inline int nxt(int x) {
    return x + x - prv(x);
}


void getint(int& x) {
    x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    do {
        x = x * 10 + c - '0';
        c = getchar();
    } while (c >= '0' && c <= '9');
}

const int N = 300333;
const int M = 1200000;
int a[N], sum[N];
pair<int, int> b[N];
int toleft[N], toright[N];

vector<int> g[M];

int was[M], cans[M];
int IT = 0;

int n, k;
inline int getplace(int l, int r, int x) {
    if (was[x] == IT) return cans[x];
    was[x] = IT;
    if (l <= r) {
        cans[x] = upper_bound(begin(g[x]), end(g[x]), r) - lower_bound(begin(g[x]), end(g[x]), l);
    } else {
        cans[x] = 0;
    }
    return cans[x];
}

int main() {
    getint(n); getint(k);
    ll ans = 0;
    g[0].push_back(0);
    for (int i = 1; i <= n; ++i) {
        getint(a[i]);
        b[i - 1].first = a[i];
        b[i - 1].second = i;

        toleft[i] = i - 1;
        toright[i] = i + 1;

        sum[i] = (a[i] + sum[i - 1]) % k;
        g[sum[i]].push_back(i);

    }
    ans -= n;
    sort(b, b + n);
    toright[0] = 1; toleft[n + 1] = n;

    for (int i = 0; i < n; ++i) {
        ++IT;
        int place = b[i].second;
        int value = b[i].first % k;

        int from = toleft[place];
        int to = toright[place] - 1;

        toleft[toright[place]] = toleft[place];
        toright[toleft[place]] = toright[place];


        if (place - from < to - place) {
            for (int i = from; i < place; ++i) {
                ans += getplace(place, to, (sum[i] + value) % k);
            }
        } else {
            for (int i = place; i <= to; ++i) {
                ans += getplace(from, place - 1, (sum[i] + k - value) % k);
            }
        }
    }

    cout << ans << endl;

    return 0;
}