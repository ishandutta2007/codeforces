#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

const int N = 1005;

int n;
long long a[N];
map<long long, int> cnt;
stack<long long> s;

long long abss(long long x) {
    if (x < 0) return -x;
    return x;
}

int main() {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        cnt[a[i]]++;
        if (!a[i]) ans++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (!a[i] && !a[j]) continue;
            int cao = 2;
            long long u1 = a[i]; long long u2 = a[j];
            s.push(u1); s.push(u2);
            cnt[u1]--; cnt[u2]--;
            while (1) {
               // if (abss(u1 + u2) > 1000000000LL) break;
                if (cnt[u1 + u2] == 0) break;
                s.push(u1 + u2);
                cnt[u1 + u2]--;
                cao++;
                long long tmp = u2;
                u2 = u1 + u2;
                u1 = tmp;
            }
            ans = max(ans, cao);
            while (!s.empty()) {
                cnt[s.top()]++;
                s.pop();
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}