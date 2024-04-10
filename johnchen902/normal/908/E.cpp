#include <cstdio>
using namespace std;
constexpr int mod = 1000000007;

char s[50][1001];
bool vis[1000];
int bell[1001][1001];

bool check(int i, int j, int n) {
    for (int k = 0; k < n; k++)
        if (s[k][i] != s[k][j])
            return false;
    return true;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);

    bell[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        bell[i][0] = bell[i - 1][i - 1];
        for (int j = 1; j <= i; j++)
            bell[i][j] = (bell[i][j - 1] + bell[i - 1][j - 1]) % mod;
    }

    int ans = 1;
    for (int i = 0; i < m; i++) {
        if (!vis[i]) {
            int cnt = 1;
            for (int j = i + 1; j < m; j++)
                if (!vis[j] && check(i, j, n)) {
                    cnt++;
                    vis[j] = true;
                }   
            ans = ans * 1LL * bell[cnt][0] % mod;
        }
    }
    printf("%d\n", ans);
}