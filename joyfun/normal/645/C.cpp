#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, k, cnt[N];
char str[N];

bool judge(int x) {
    for (int i = 1; i <= n; i++) {
        if (str[i] == '1') continue;
        int l = max(1, i - x);
        int r = min(i + x, n);
        if (cnt[r] - cnt[l - 1] >= k + 1) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + ((str[i] - '0')^1);
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r)>>1;
        if (judge(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}