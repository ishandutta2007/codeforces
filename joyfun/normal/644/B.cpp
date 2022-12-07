#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 200005;
int n, b;
queue<int> Q;
long long ans[N], t[N], d[N];

int main() {
    scanf("%d%d", &n, &b);
    long long pre = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &t[i], &d[i]);
        while (Q.size() && pre <= t[i]) {
            pre = max(pre, t[Q.front()]) + d[Q.front()];
            ans[Q.front()] = pre;
            Q.pop();
        }
        if (Q.size() == b) ans[i] = -1;
        else Q.push(i);
    }
    while (Q.size()) {
        pre = max(pre, t[Q.front()]) + d[Q.front()];
        ans[Q.front()] = pre;
        Q.pop();
    }
    for (int i = 0; i < n; i++) printf("%lld ", ans[i]);
    printf("\n");
    return 0;
}