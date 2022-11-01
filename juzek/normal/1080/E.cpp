#include <cstdio>
#include <algorithm>

char s[257][257];
long long wsp['z' + 7];
long long hashe[257];
int dl[257];
int zle[257];
bool ok[257];
bool ile[257]['z'];
const int mod = 1000000007;

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%s", s[i] + 1);
    wsp['a'] = 251;
    for (int i = 'b'; i <= 'z'; i++) {
        wsp[i] = wsp[i - 1] * 251;
        wsp[i] %= mod;
    }
    long long wyn = 0;
    for (int pocz = 1; pocz <= M; pocz++) {
        for (int y = 1; y <= N; y++) {
            hashe[y] = 0;
            zle[y] = 0;
            for (int i = 'a'; i <= 'z'; i++)
                ile[y][i] = false;
        }
        for (int kon = pocz; kon <= M; kon++) {
            bool kk = bool((kon - pocz + 1) % 2);
            for (int y = 1; y <= N; y++) {
                hashe[y] += wsp[s[y][kon]];
                hashe[y] %= mod;
                ile[y][s[y][kon]] = !ile[y][s[y][kon]];
                if (ile[y][s[y][kon]])
                    zle[y]++;
                else
                    zle[y]--;
                ok[y] = kk ? zle[y] == 1 : zle[y] == 0;
            }
            int l = 0, r = 0;
            for (int y = 1; y <= N; y++) {
                if (!ok[y]) {
                    dl[y] = 0;
                    continue;
                }
                int ter = r < y ? 1 : std::min(dl[l + r - y], r - y + 1);
                while (y - ter >= 1 && y + ter <= N && ok[y - ter] && ok[y + ter] && hashe[y - ter] == hashe[y + ter])
                    ter++;
                dl[y] = ter--;
                wyn += dl[y];
                if (y + ter > r)
                    r = y + ter, l = y - ter;
            }
            l = 0, r = 0;
            for (int y = 1; y <= N; y++) {
                if (!(ok[y - 1] && ok[y] && hashe[y - 1] == hashe[y])) {
                    dl[y] = 0;
                    continue;
                }
                int ter = r < y ? 1 : std::min(dl[l + r - y + 1], r - y + 1);
                while (y - ter - 1 >= 1 && y + ter <= N && ok[y - ter - 1] && ok[y + ter] && hashe[y - ter - 1] == hashe[y + ter])
                    ter++;
                dl[y] = ter--;
                wyn += dl[y];
                if (y + ter > r)
                    r = y + ter, l = y - ter - 1;
            }
        }
    }
    printf("%lld", wyn);
    return 0;
}