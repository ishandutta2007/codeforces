#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long llong;

int n, k, A;
int X[100001];
int C[100001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> X[i];
    cin >> A;
    for (int i = 1; i <= n; ++i) cin >> C[i];
    priority_queue<int> pq;
    int cnt = 0;
    llong ans = 0;
    for (int i = 1; i <= n; ++i) {
        int need = (max(X[i] - k, 0) + A - 1) / A;
        pq.push(-C[i]);
        while (cnt < need) {
            if (pq.empty()) {
                printf("-1\n");
                return 0;
            }
            ans -= pq.top();
            pq.pop();
            ++cnt;
        }
    }
    printf("%lld\n", ans);
    return 0;
}