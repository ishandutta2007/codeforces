#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, m, tmp[N], a[N], top;
pair<int, int> st[N];

long long solve() {
    int Max = 0;
    long long ans = 0, sum = 0;
    top = 0;
    for (int i = 2; i <= n; i++) {
        int tmp = abs(a[i] - a[i - 1]);
        while (top && st[top].first < tmp) {
            sum -= 1LL * st[top].first * (st[top].second - st[top - 1].second);
            top--;
        }
        st[++top] = make_pair(tmp, i - 1);
        sum += 1LL * st[top].first * (st[top].second - st[top - 1].second);
        ans += sum;
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &tmp[i]);
    int l, r;
    while (m--) {
        scanf("%d%d", &l, &r);
        n = 0;
        for (int i = l; i <= r; i++) a[++n] = tmp[i];
        printf("%lld\n", solve());
    }
    return 0;
}