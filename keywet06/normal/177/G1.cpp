#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 3005;
const int P = 1000000007;

char s[N];

int k, m, len;
int pw3[N], H1[N], H2[N], res[N];
int lh[N][N], rh[N][N];

void Init(int k) {
    if (lh[k][0] != -1) return;
    if (k == 1) {
        lh[k][0] = rh[k][0] = 0;
    } else if (k == 2) {
        lh[k][0] = rh[k][0] = 1;
    } else {
        Init(k - 1);
        Init(k - 2);
        int i = 0;
        while (i < N && lh[k - 1][i] != -1) lh[k][i] = lh[k - 1][i], ++i;
        int j = 0;
        while (i + j < N && lh[k - 2][j] != -1) {
            lh[k][i + j] = (lh[k - 1][i - 1] +
                            int64(pw3[i]) * int64(lh[k - 2][j]) % int64(P)) %
                           P;
            ++j;
        }
        i = 0;
        while (i < N && rh[k - 2][i] != -1) rh[k][i] = rh[k - 2][i], ++i;
        j = 0;
        while (i + j < N && rh[k - 1][j] != -1) {
            rh[k][i + j] =
                (rh[k - 1][j] +
                 int64(pw3[j + 1]) * int64(rh[k - 2][i - 1]) % int64(P)) %
                P;
            ++j;
        }
    }
}

int getRes(int k) {
    if (k == 1) return len == 1 && s[0] == 'a';
    if (k == 2) return len == 1 && s[0] == 'b';
    if (res[k] == -1) {
        res[k] = (getRes(k - 1) + getRes(k - 2)) % P;
        for (int i = 0; i < len - 1; ++i)
            res[k] = (res[k] + (rh[k - 1][i] == H1[i] &&
                                lh[k - 2][len - i - 2] == H2[len - i - 2])) %
                     P;
    }
    return res[k];
}

int main() {
    pw3[0] = 1;
    for (int i = 1; i < N; ++i) pw3[i] = int64(pw3[i - 1]) * 3LL % int64(P);
    fill((int*)lh, (int*)lh + N * N, -1);
    fill((int*)rh, (int*)rh + N * N, -1);
    scanf("%d %d", &k, &m);
    Init(k);
    while (m--) {
        scanf("%s", s);
        len = strlen(s);
        H1[0] = s[0] - 'a';
        for (int i = 1; i < len; ++i)
            H1[i] =
                (H1[i - 1] + int64(pw3[i]) * int64(s[i] - 'a') % int64(P)) % P;
        H2[0] = s[len - 1] - 'a';
        for (int i = 1; i < len; ++i)
            H2[i] =
                (s[len - 1 - i] - 'a' + 3LL * int64(H2[i - 1]) % int64(P)) % P;
        fill(res, res + k + 1, -1);
        printf("%d\n", getRes(k));
    }
    return 0;
}