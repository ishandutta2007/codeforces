#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <bitset>
#include <functional>

std::map<int, int> stany[47];

int prz[47]['z' + 1];
char s[27][27];
int N;

void ogarnij(int pos, int maska) {
    if (stany[pos].count(maska) == 1)
        return;
    if (pos == 2 * N - 2) {
        stany[pos][maska] = 0;
        return;
    }
    int stan = -1337133713;
    for (char lit = 'a'; lit <= 'z'; lit++) {
        int ter = (prz[pos + 1][lit] & maska) | (prz[pos + 1][lit] & (maska << 1));
        if (ter == 0)
            continue;
        ogarnij(pos + 1, ter);
        int wartosc = lit == 'a' ? 1 : lit == 'b' ? -1 : 0;
        if (pos % 2 == 0)
            wartosc = -wartosc;
        stan = std::max(stan, wartosc - stany[pos + 1][ter]);
    }
    stany[pos][maska] = stan;
}

void wypisz(int a) {
    std::bitset<32> b = a;
    for (int i = 0; i <= 2; i++)
        printf("%d", (int) b[i]);
    printf("\n");
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%s", s[i]);
    for (int i = 0; i < 2 * N - 1; i++) {
        for (int lit = 'a'; lit <= 'z'; lit++) {
            int terMask = 0;
            if (i >= N) {
                for (int y = 0; y <= 2 * N - i - 2; y++)
                    if (s[y + i - N + 1][N - y - 1] == lit)
                        terMask |= (1 << (y + i - N + 1));
            } else {
                for (int y = 0; y <= i; y++)
                    if (s[y][i - y] == lit)
                        terMask |= (1 << y);
            }
            prz[i][lit] = terMask;
        }
    }
    ogarnij(0, 1);
    char lit = s[0][0];
    int wartosc = lit == 'a' ? 1 : lit == 'b' ? -1 : 0;
    int wyn = wartosc - stany[0][1];
    printf(wyn == 0 ? "DRAW" : wyn > 0 ? "FIRST" : "SECOND");
    return 0;
}