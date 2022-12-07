#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, k, a[N];
int bit[N];

#define lowbit(x) (x&(-x))

void add(int x, int v) {
    while (x <= n) {
        bit[x] += v;
        x += lowbit(x);
    }
}

int get(int x) {
    int ans = 0;
    while (x) {
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        a[i] = i;
    for (int i = 1; i <= k && i <= n / 2; i++)
        swap(a[i], a[n - i + 1]);
    long long ans = 0;
    //for (int i = 1; i <= n; i++) printf("%d ", a[i]); printf("\n");
    for (int i = n; i >= 1; i--) {
        ans += get(a[i]);
        add(a[i], 1);
    }
    printf("%lld\n", ans);
    return 0;
}