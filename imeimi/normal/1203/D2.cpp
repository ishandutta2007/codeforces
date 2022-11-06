#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

int n, m;
char S[200002];
char T[200002];
int F[200002][26];
int L[200002][26];
int Pidx[200002];
int Sidx[200002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S + 1 >> T + 1;
    n = strlen(S + 1);
    m = strlen(T + 1);
    for (int i = 0; i < 26; ++i) {
        F[n][i] = n + 1;
        L[1][i] = 0;
    }
    for (int i = n; i > 0; --i) {
        for (int j = 0; j < 26; ++j) {
            F[i - 1][j] = F[i][j];
        }
        F[i - 1][S[i] - 'a'] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            L[i + 1][j] = L[i][j];
        }
        L[i + 1][S[i] - 'a'] = i;
    }
    for (int i = 1; i <= m; ++i) {
        Pidx[i] = F[Pidx[i - 1]][T[i] - 'a'];
    }
    Sidx[m + 1] = n + 1;
    for (int i = m; i > 0; --i) {
        Sidx[i] = L[Sidx[i + 1]][T[i] - 'a'];
    }
    int ans = 0;
    for (int i = 0; i <= m; ++i) {
        ans = max(ans, Sidx[i + 1] - Pidx[i] - 1);
    }
    printf("%d\n", ans);
    return 0;
}