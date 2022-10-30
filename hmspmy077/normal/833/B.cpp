#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 35000;
const int M = 50;

int last[N], prev[N + 1], dp[M + 1][N + 1], delta[N + 1 << 1], maximum[N + 1 << 1];

int get_id(int l, int r)
{
    return l + r | l != r;
}

void update(int l, int r)
{
    int m = l + r >> 1;
    int id = get_id(l, r);
    maximum[id] = std::max(maximum[get_id(l, m)], maximum[get_id(m + 1, r)]) + delta[id];
}

void add(int l, int r, int a, int b, int c)
{
    if (b < l || r < a) {
        return;
    }
    int id = get_id(l, r);
    if (a <= l && r <= b) {
        delta[id] += c;
        maximum[id] += c;
    } else {
        int m = l + r >> 1;
        add(l, m, a, b, c);
        add(m + 1, r, a, b, c);
        update(l, r);
    }
}



int main()
{
#ifdef LOCAL_JUDGE
    freopen("B.in", "r", stdin);
#endif
    int n, m;
    while (scanf("%d%d", &n, &m) == 2)
    {
        memset(last, -1, sizeof(last));
        for (int i = 1; i <= n; ++ i) {
            int a;
            scanf("%d", &a);
            a --;
            prev[i] = last[a];
            last[a] = i;
        }
        dp[1][0] = 0;
        for (int i = 1; i <= n; ++ i) {
            dp[1][i] = dp[1][i - 1] + (prev[i] == -1);
        }
        for (int j = 2; j <= m; ++ j) {
            memset(delta, 0, sizeof(delta));
            memset(maximum, 0, sizeof(maximum));
            int L = j;
            int R = n;
            for (int i = j; i <= n; ++ i) {
                add(L, R, i, i, dp[j - 1][i - 1]);
                add(L, R, prev[i] + 1, i, 1);
                dp[j][i] = maximum[get_id(L, R)];
            }
        }
        printf("%d\n", dp[m][n]);
    }
}