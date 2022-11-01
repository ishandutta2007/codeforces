#include <cstdio>
#include <algorithm>
using namespace std;

constexpr long long inf = 1e13;

bool blocked[1000000];
int prev[1000000];
int a[1000000];

long long solve(int n, int k) {
    if (blocked[0])
        return -1;
    for (int i = 1, p = 0; i < n; i++) {
        if (!blocked[i])
            p = i;
        ::prev[i] = p;
    }

    long long ans = inf;
    for (int step = 1; step <= k; step++) {
        int cnt = 1;
        for (int x = 0; x + step < n; x = ::prev[x + step], cnt++)
            if (x == ::prev[x + step])
                goto nextfor;
        ans = min(ans, (long long) a[step - 1] * cnt);
nextfor:
        ;
    }
    return ans >= inf ? -1 : ans;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int s;
        scanf("%d", &s);
        blocked[s] = true;
    }
    for (int i = 0; i < k; i++)
        scanf("%d", a + i);

    printf("%lld\n", solve(n, k));
}