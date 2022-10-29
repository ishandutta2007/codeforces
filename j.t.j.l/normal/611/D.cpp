#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 5E3 + 10;
const ll MOD = 1E9 + 7;

int cnt[10];

char s[MAXN];
int a[MAXN], rank[MAXN][MAXN];
int trank[MAXN];

ll f[MAXN][MAXN];

int main(){
    scanf("%*d%s", s);
    int n = strlen(s);

    for (int i = 0; i < n; ++i)
        a[i] = i;

    int pre[11], cnt[11];
    for (int len = 0; len < n; ++len){

        memset(cnt, 0, sizeof(cnt));//size 11, NULL + 10
        memset(pre, -1, sizeof(pre));
        for (int i = 0; i < n; ++i){
            int t = a[i] < len ? 0 : s[a[i] - len] - '0' + 1;
            ++cnt[t];
        }

        for (int i = 1; i <= 10; ++i)
            cnt[i] += cnt[i - 1];

        for (int i = n - 1; i >= 0; --i){
            int t = a[i] < len ? 0 : s[a[i] - len] - '0' + 1;
            if (pre[t] == -1 || rank[len][a[i]] < rank[len][pre[t]]){
                rank[len + 1][a[i]] = pre[t] == -1 ? cnt[t] : rank[len + 1][pre[t]] - 1;
                pre[t] = a[i];
            }
            else
                rank[len + 1][a[i]] = rank[len + 1][pre[t]];
            
            trank[a[i]] = --cnt[t];
        //  printf("%d ", a[i]);
        }

//      for (int i = 0; i < n; ++i)
//          printf("%d ", rank[len + 1][i]);
//      puts("");

        for (int i = 0; i < n; ++i)
            a[trank[i]] = i;
    }

    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j){
            f[i][j] = (f[i][j] + (j ? f[i][j - 1] : 0)) % MOD;
//          printf("%d %d %I64d\n", i, j, f[i][j]);

            if (j == n - 1 || s[j + 1] == '0')
                continue;
            int k = j + j - i + 1;
            if (k < n && rank[j - i + 1][j] < rank[j - i + 1][k]){
                f[j + 1][k] += f[i][j];
//              printf("(%d,%d)->(%d,%d)\n", i, j, j + 1, k);
            }
            else if (k + 1 < n){
                f[j + 1][k + 1] += f[i][j];
//              printf("(%d,%d)->(%d,%d)\n", i, j, j + 1, k + 1);
            }
        }

    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans = (ans + f[i][n - 1]) % MOD;

    printf("%I64d\n", ans);

    return 0;
}