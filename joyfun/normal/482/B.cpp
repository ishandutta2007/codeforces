#include <cstdio>
#include <cstring>

const int N = 100005;
int n, m, cnt[30][N], sum[30][N];

int l[N], r[N], val[N];

bool judge() {
    for (int i = 0; i < m; i++) {
        int tmp = val[i];
        int cn = 0;
        for (int j = 0; j < 30; j++) {
            if (tmp % 2) {
                if (sum[cn][r[i]] - sum[cn][l[i] - 1] != r[i] - l[i] + 1) return false;
            } else {
                if (sum[cn][r[i]] - sum[cn][l[i] - 1] == r[i] - l[i] + 1) return false;
            }
            tmp /= 2;
            cn++;
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &l[i], &r[i], &val[i]);
        int tmp = val[i];
        int cn = 0;
        while (tmp) {
            if (tmp % 2) {
                cnt[cn][l[i]]++;
                cnt[cn][r[i] + 1]--;
            }
            tmp /= 2;
            cn++;
        }
    }
    for (int i = 0; i < 30; i++) {
        for (int j = 1; j <= n + 1; j++) {
            cnt[i][j] += cnt[i][j - 1];
            if (cnt[i][j - 1]) cnt[i][j - 1] = 1;
        }
    }
    /*
    for (int i = 0; i <= 1; i++)
        for (int j = 1; j <= 3; j++)
            printf("%d %d %d!!\n", i, j, cnt[i][j]);*/
    for (int i = 0; i < 30; i++) {
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i][j - 1] + cnt[i][j];
    }
    /*
    for (int i = 0; i <= 1; i++)
        for (int j = 1; j <= 3; j++)
            printf("%d %d %d!!\n", i, j, sum[i][j]);
            */
    if (judge()) {
        printf("YES\n");
        int bo = 0;
        for (int i = 1; i <= n; i++) {
            int ans = 0;
            for (int j = 29; j >= 0; j--) {
                ans = ans * 2 + cnt[j][i];
            }
            if (bo) printf(" ");
            else bo = 1;
            printf("%d", ans);
        }
        printf("\n");
    } else printf("NO\n");
    return 0;
}