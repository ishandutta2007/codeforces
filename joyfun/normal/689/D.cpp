#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;
int ha, hb, ma, mi;
pair<int, int> a[N], b[N];
int n;
int aa[N], bb[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &aa[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &bb[i]);
    long long ans = 0;
    int s = 1;
    ma = ha = mi = hb = 0;
    for (int i = 1; i <= n; i++) {
        while (ma > ha && a[ma - 1].first <= aa[i]) ma--;
        a[ma++] = make_pair(aa[i], i);
        while (mi > hb && b[mi - 1].first >= bb[i]) mi--;
        b[mi++] = make_pair(bb[i], i);
        while (s <= i && ha < ma && hb < mi && a[ha].first > b[hb].first) {
            s++;
            if (a[ha].second < s) ha++;
            if (b[hb].second < s) hb++;
        }
        if (s <= i && ha < ma && hb < mi && a[ha].first == b[hb].first)
            ans += min(a[ha].second, b[hb].second) - s + 1;
    }
    printf("%lld\n", ans);
    return 0;
}