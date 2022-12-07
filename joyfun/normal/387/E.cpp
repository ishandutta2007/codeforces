#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
const int N = 1000005;
#include <set>
using namespace std;
#define INF 0x3f3f3f3f

int n, k, v[N], vis[N], i, bit[N];

void Insert(int x, int v) {
    while (x <= n) {
        bit[x] += v;
        x += (x&(-x));
    }
}

int Sum(int x) {
    int ans = 0;
    while (x > 0) {
        ans += bit[x];
        x -= (x&(-x));
    }
    return ans;
}

__int64 solve() {
    __int64 ans = 0;
    set<int> s;
    s.insert(0);
    s.insert(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            s.insert(v[i]);
        }
        else {
            set<int>::iterator it = s.lower_bound(v[i]);
            int r = *it - 1;
            int l = *(--it);
            ans += Sum(r) - Sum(l);
            Insert(v[i], -1);
        }
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &k);
    int num;
    for (i = 1; i <= n; i++) {
        scanf("%d", &num);
        v[num] = i;
        Insert(i, 1);
    }
    for (i = 1; i <= k; i++) {
        scanf("%d", &num);
        vis[num] = 1;
    }
    printf("%I64d\n", solve());
    return 0;
}