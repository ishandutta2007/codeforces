#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
constexpr long long maxt = 2000000000;
int n, k, b, c;
int t[200000];
priority_queue<long long> pq[5];
long long sum[5];
void add(int tt) {
    for(int i = 0; i < 5; i++) {
        long long tm = (maxt - tt + i) / 5 * b + (maxt - tt + i) % 5 * c;
        sum[i] += tm;
        pq[i].push(tm);
        if((int) pq[i].size() > k) {
            sum[i] -= pq[i].top();
            pq[i].pop();
        }
    }
}
long long test(int tt) {
    return sum[tt % 5] - (maxt + tt % 5 - tt) / 5 * k * b;
}
int main() {
    scanf("%d %d %d %d", &n, &k, &b, &c);
    for(int i = 0; i < n; i++)
        scanf("%d", t + i), t[i] += maxt / 2;
    if(b > c * 5)
        b = c * 5;
    sort(t, t + n);
    long long ans = maxt * k * c;
    for(int i = 0; i < n; i++) {
        add(t[i]);
        if(i >= k - 1) {
            for(int j = 0; j < 5; j++)
                ans = min(ans, test(t[i] + j));
        }
    }
    printf("%lld\n", ans);
}