#include <cstdio>
#include <cstring>
#include <vector>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;
char s[200005];
int c[22][22];
int t[22], T;
long long r[1<<22];
int real[22];

int main() {
    scanf("%d %d %d", &n, &k, &T);
    scanf(" %s", s);
    FO(i,0,n) real[s[i]-'A'] = 1;
    FO(i,0,k) {
        scanf("%d", t+i);
        if (!real[i]) t[i] = 0;
    }
    FO(i,0,k) FO(j,0,k) scanf("%d", c[i]+j);

    FO(i,0,k) FO(j,0,k) {
        int p = -1;
        int allowed = (1<<k)-1;
        allowed &= ~(1<<i);
        allowed &= ~(1<<j);
        FO(a,0,n) {
            allowed &= ~(1<<(s[a]-'A'));
            if (p != -1 && s[a] == 'A'+j) {
                if (i != j) {
                    r[allowed|(1<<i)|(1<<j)] += c[i][j];
                    r[allowed|(1<<i)] -= c[i][j];
                    r[allowed|(1<<j)] -= c[i][j];
                    r[allowed] += c[i][j];
                } else {
                    r[allowed|(1<<i)] += c[i][j];
                    r[allowed] -= c[i][j];
                }
                p = -1;
            }
            if (s[a] == 'A'+i) {
                allowed = (1<<k)-1;
                allowed &= ~(1<<i);
                allowed &= ~(1<<j);
                p = a;
            }
        }
    }
    FO(i,0,k) {
        r[((1<<k)-1)^(1<<i)] += t[i];
    }
    int res = 0;
    for (int j = k-1; j >= 0; j--) {
        for (int i = 0; i < (1<<k); i++) {
            if (~i&(1<<j)) r[i] += r[i|(1<<j)];
        }
    }
    FO(i,1,1<<k) {
        if (r[i] <= T) {
            FO(j,0,k) if (!real[j] && (i&(1<<j))) goto nxt;
            res++;
        }
nxt:;
    }
    printf("%d\n", res);
}