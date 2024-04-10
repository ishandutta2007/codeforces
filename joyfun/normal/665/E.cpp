#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
int ch[32000005][2], val[32000005];
int sz = 1;

int get(int s) {
    int ans = 0;
    int u = 0;
    for (int i = 30; i >= 0; i--) {
        int t1 = ((k>>i)&1);
        int t2 = ((s>>i)&1);
        if (ch[u][0] && t2 > t1) ans += val[ch[u][0]];
        if (ch[u][1] && (t2^1) > t1) ans += val[ch[u][1]];
        int flag = 0;
        if (ch[u][0] && t2 == t1) {
            u = ch[u][0];
            flag = 1;
        }
        if (ch[u][1] && (t2^1) == t1) {
            u = ch[u][1];
            flag = 1;
        }
        if (!flag) return ans;
    }
    return ans;
}

void ins(int s) {
    int u = 0;
    for (int i = 30; i >= 0; i--) {
        int tmp = ((s>>i)&1);
        if (!ch[u][tmp]) {
            val[sz] = 0;
            ch[u][tmp] = sz++;
        }
        u = ch[u][tmp];
        val[u]++;
    }
}

int main() {
    scanf("%d%d", &n, &k);
    k--;
    int x, s = 0;
    long long ans = 0;
    ins(0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        s ^= x;
        ans += get(s);
        ins(s);
    }
    printf("%lld\n", ans);
    return 0;
}