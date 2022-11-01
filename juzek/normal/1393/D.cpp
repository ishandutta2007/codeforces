#include <bits/stdc++.h>

using namespace std;

char s[2007][2007];
int lewo[2007][2007], prawo[2007][2007];
int dp_dol[2007][2007], dp_gora[2007][2007];

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf(" %s", s[i] + 1);
        for (int w = 1; w <= M; w++)
            lewo[i][w] = s[i][w] == s[i][w - 1] ? lewo[i][w - 1] + 1 : 1;
        for (int w = M; w >= 1; w--)
            prawo[i][w] = s[i][w] == s[i][w + 1] ? prawo[i][w + 1] + 1 : 1;
    }
    long long odp = 0;
    for (int w = 1; w <= M; w++) {
        for (int i = 1; i <= N; i++) {
            int ja = min(lewo[i][w], prawo[i][w]);
            if (s[i][w] == s[i - 1][w])
                dp_gora[i][w] = min(ja, dp_gora[i - 1][w] + 1);
            else
                dp_gora[i][w] = 1;
        }
        for (int i = N; i >= 1; i--) {
            int ja = min(lewo[i][w], prawo[i][w]);
            if (s[i][w] == s[i + 1][w])
                dp_dol[i][w] = min(ja, dp_dol[i + 1][w] + 1);
            else
                dp_dol[i][w] = 1;
        }
        for (int i = 1; i <= N; i++)
            odp += min(dp_gora[i][w], dp_dol[i][w]);
    }
    printf("%lld", odp);
    return 0;
}