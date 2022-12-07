#include <stdio.h>
#include <string.h>
#include <algorithm>
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1111111;
const int N = 105;
const int M = 25;

int cmp(int a, int b) {
    return a > b;
}

int n, m, s[N], c[M], t[M], dp[MAXN], st;

void init() {
    memset(dp, INF, sizeof(dp));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    scanf("%d%*c", &m);
    for (int j = 0; j < m; j++)
        scanf("%c%*c%d%*c", &c[j], &t[j]);
}

int DP(int state, int num) {
    if (dp[state] != INF) return dp[state];
    int &ans = dp[state];
    ans = 0;
    if (c[num] == 'p') {
        int bit;
        for (bit = 0; bit < m; bit++)
            if ((state & (1<<bit)))
                break;
        if (t[num] == 1)
            ans = (DP((state^(1<<bit)), num + 1) + s[bit]);
        else
            ans = (DP((state^(1<<bit)), num + 1) - s[bit]);
    }
    else if (c[num] == 'b') {
        if (t[num] == 1) ans = -INF;
        else ans = INF;
        for (int i = 0; i < m; i++) {
            if ((state & (1<<i))) {
                if (t[num] == 1)
                    ans = max(ans, DP((state^(1<<i)), num + 1));
                else 
                    ans = min(ans, DP((state^(1<<i)), num + 1));
            }
        }
    }
    return ans;
}

void solve() {
    sort(s, s + n, cmp);
    st = (1<<m) - 1;
    printf("%d\n", DP(st, 0));
}

int main() {
    init();
    solve();
    return 0;
}