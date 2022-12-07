#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 500005;

int n;
ll a, b, T;
char str[N];
ll pre[N], suf[N];

bool judge(int mid) {
    for (int i = 1; i < mid; i++) {
        ll left = pre[i] + a * i + suf[n - (mid - i) + 1];
        ll right = a + suf[n - (mid - i) + 1] + a * (mid - i) + pre[i];
        if (min(left, right) <= T) return true;
    }
    if (pre[mid] <= T) return true;
    return false;
}

int main() {
    scanf("%d%lld%lld%lld", &n, &a, &b, &T);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + 1;
        if (i != 1) pre[i] += a;
        if (str[i] == 'w') pre[i] += b;
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + 1;
        if (i != n) suf[i] += a;
        if (str[i] == 'w') suf[i] += b;
    }
    int l = 1, r = n + 1;
    while (l < r) {
        int mid = (l + r)>>1;
        if (judge(mid)) l = mid + 1;
        else r = mid;
    }
    printf("%d\n", l - 1);
    return 0;
}