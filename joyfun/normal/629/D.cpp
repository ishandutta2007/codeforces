#include <cstdio>
#include <cstring>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 100005;
const double pi = acos(-1.0);

typedef long long ll;

int n, hn;
ll vol[N], h[N];
ll bit[N];

#define lowbit(x) (x&(-x))

void add(int x, ll v) {
    while (x <= hn) {
        bit[x] = max(bit[x], v);
        x += lowbit(x);
    }
}

ll get(int x) {
    ll ans = 0;
    while (x) {
        ans = max(ans, bit[x]);
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int r, hh;
        scanf("%d%d", &r, &hh);
        vol[i] = 1LL * r * r * hh;
        h[i] = vol[i];
    }
    sort(h + 1, h + n + 1);
    hn = unique(h + 1, h + 1 + n) - h - 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int id = lower_bound(h + 1, h + 1 + hn, vol[i]) - h;
        ll Max = get(id - 1) + vol[i];
        ans = max(ans, Max);
        add(id, Max);
    }
    printf("%.12f\n", pi * ans);
    return 0;
}