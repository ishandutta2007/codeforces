#include <stdio.h>
#include <string.h>
const int N = 105;

int k, x, n, m;
__int64 f[N];
char ans[N], s[N], e[N];

void init() {
    scanf("%d%d%d%d", &k, &x, &n, &m);
}

void print(char s, char e, int len, int num) {
    memset(ans, 0, sizeof(ans));
    ans[0] = s; ans[len - 1] = e;
    int i, bo = (s == 'A' ? 0 : 1);
    for (i = 1; i < len - 1; i++)
        ans[i] = 'B';
    for (i = 0; i < num; i++) {
        ans[bo + 2 * i] = 'A';
        ans[bo + 2 * i + 1] = 'C';
    }
    printf("%s\n", ans);
}

bool ISOK(char s1, char e1, char s2, char e2, int xx, int yy) {
    s[1] = s1; e[1] = e1; s[2] = s2; e[2] = e2; f[1] = xx; f[2] = yy;
    for (int i = 3; i <= k; i ++) {
        s[i] = s[i - 2];
        e[i] = e[i - 1];
        f[i] = f[i - 1] + f[i - 2] + (e[i - 2] == 'A' && s[i - 1] == 'C');
    }
    if (f[k] == x)
        return true;
    return false;
}

bool judge() {
    for (char s1 = 'A'; s1 <= 'C'; s1++) {
        for (char e1 = 'A'; e1 <= 'C'; e1++) {
            if (n == 1 && s1 != e1) continue;
            for (char s2 = 'A'; s2 <= 'C'; s2++) {
                for (char e2 = 'A'; e2 <= 'C'; e2++) {
                    if (m == 1 && s2 != e2) continue;
                    int lx = n - (s1 != 'A') - (e1 != 'C');
                    int ly = m - (s2 != 'A') - (e2 != 'C');
                    lx /= 2; ly /= 2;
                    for (int xx = 0; xx <= lx; xx++)
                        for (int yy = 0; yy <= ly; yy++) {
                            if (n == 2 && s1 == 'A' && e1 == 'C' && xx == 0) continue;
                            if (m == 2 && s2 == 'A' && e2 == 'C' && yy == 0) continue;
                            if (ISOK(s1, e1, s2, e2, xx, yy)) {
                                print(s1, e1, n, xx);
                                print(s2, e2, m, yy);
                                return true;
                            }
                        }
                }
            }
        }
    }
    return false;
}

void solve() {
    if (!judge())
        printf("Happy new year!\n");
}

int main() {
    init();
    solve();
    return 0;
}