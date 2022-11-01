#include <cstdio>
#include <utility>
#include <cstring>

int punkty[5][5][3];
bool odw[5][5];
int mA[5][5], mB[5][5];
int chwila[5][5];
int cyklWar[2];
int cyklLen = -1;
int cyklPunkty[3];
long long zostalo;
long long wynik[3];

int kto(int a, int b) {
    if (a == b)
        return 2;
    if (b == a + 1 || (b == 1 && a == 3))
        return 1;
    else
        return 0;
}

void dfs(int a, int b, int pA, int pB, int ter) {
    odw[a][b] = true;
    chwila[a][b] = ter;
    punkty[a][b][0] = pA;
    punkty[a][b][1] = pB;
    punkty[a][b][kto(a, b)]++;
    wynik[kto(a, b)]++;
    zostalo--;
    if (zostalo == 0)
        return;
    int ma = mA[a][b], mb = mB[a][b];
    if (odw[ma][mb]) {
        cyklLen = ter - chwila[ma][mb] + 1;
        cyklPunkty[0] = punkty[a][b][0] - punkty[ma][mb][0];
        cyklPunkty[1] = punkty[a][b][1] - punkty[ma][mb][1];
        cyklPunkty[kto(ma, mb)]++;
        cyklWar[0] = ma, cyklWar[1] = mb;
    } else
        dfs(ma, mb, punkty[a][b][0], punkty[a][b][1], ter + 1);
}

int main() {
    int A, B;
    scanf("%lld%d%d", &zostalo, &A, &B);
    for (int i = 1; i <= 3; i++)
        for (int w = 1; w <= 3; w++)
            scanf("%d", &mA[i][w]);
    for (int i = 1; i <= 3; i++)
        for (int w = 1; w <= 3; w++)
            scanf("%d", &mB[i][w]);
    dfs(A, B, 0, 0, 1);
    wynik[0] += cyklPunkty[0] * (zostalo / cyklLen);
    wynik[1] += cyklPunkty[1] * (zostalo / cyklLen);
    zostalo %= cyklLen;
    memset(odw, 0, sizeof(odw));
    if (zostalo != 0)
        dfs(cyklWar[0], cyklWar[1], 0, 0, 1);
    printf("%lld %lld\n", wynik[0], wynik[1]);
    return 0;
}