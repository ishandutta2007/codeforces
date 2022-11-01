    #include <algorithm>
    #include <cstdio>
    #include <vector>
    #include <climits>
    using namespace std;

    int main(void) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector< vector<bool> > ma(n, vector<bool>(n));
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            ma[u-1][v-1] = ma[v-1][u-1] = true;
        }
        long long res = LLONG_MAX;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j+1; k < n; k++)
                    if (ma[i][j] && ma[i][k] && ma[j][k]) {
                        res = min(res, a[i] + a[j] + a[k]);
                    }
        if (res == LLONG_MAX)
            res = -1;
            printf("%lld\n", res);
        return 0;
    }