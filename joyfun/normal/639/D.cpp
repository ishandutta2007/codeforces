#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 200005;
const int INF = 0x3f3f3f3f;

int n, k, b, c, t[N];

int main() {
    scanf("%d%d%d%d", &n, &k, &b, &c);
    if (c * 5 < b) b = c * 5;
    for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
    sort(t + 1, t + 1 + n);
    long long ans = 100000000000000000LL;
    for (int i = 0; i < 5; i++) {
        long long tmp = INF + i;
        priority_queue<long long> Q;
        long long sum = 0;
        for (int j = 1; j <= n; j++) {
            long long need = (tmp - t[j]) / 5 * b + (tmp - t[j]) % 5 * c;
            Q.push(need);
            sum += need;
            if (Q.size() > k) {
                sum -= Q.top();
                Q.pop();
            }
            if ((int)Q.size() == k) ans = min(ans, sum - (tmp - t[j]) / 5 * b * k);
        }
    }
    printf("%lld\n", ans);
    return 0;
}