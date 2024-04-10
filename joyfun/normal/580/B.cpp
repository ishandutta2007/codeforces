#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

struct SB {
    int m, s;
    void read() {
        scanf("%d%d", &m, &s);
    }
    bool operator < (const SB& c) const {
        return m < c.m;
    }
} sb[N];

int main() {
    int n, d, m, s;
    long long ans = 0;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
        sb[i].read();
    sort(sb, sb + n);
    int l = 0;
    long long now = 0;
    for (int i = 0; i < n; i++) {
        now += sb[i].s;
        while (sb[i].m - sb[l].m >= d) {
            now -= sb[l].s;
            l++;
        }
        ans = max(now, ans);
    }
    printf("%lld\n", ans);
    return 0;
}