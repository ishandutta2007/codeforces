#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n, p, s;
tuple<int,int,int> t[3005];

int f[3005][3005]; // in first i, taking j of the a, i-j of the b
int pr[3005][3005]; // in first i, taking j of the a, i-j of the b

int g[3005][3005]; // in last i, taking j of the b, no a
int pr2[3005][3005]; // in first i, taking j of the a, i-j of the b
int tp[3005];

int main() {
    scanf("%d %d %d", &n, &p, &s);
    FO(i,0,n) {
        int a; scanf("%d", &a);
        t[i] = make_tuple(a, 0, i+1);
    }
    FO(i,0,n) {
        int b; scanf("%d", &b);
        get<1>(t[i]) = b;
    }
    sort(t, t+n);

    FO(i,0,n) FO(j,i+1,n) {
        f[i][j] = -1e9;
        g[i][j] = -1e9;
    }

    reverse(t,t+n);
    FO(i,1,n+1) {
        int a, b, ind; tie(a,b,ind) = t[i-1];
        //printf("%d,%d: %d\n", a, b, ind);
        FO(j,0,i+1) {
            // take as an a
            f[i][j] = -1e9;
            if (j) {
                if (f[i-1][j-1] + a > f[i][j]) {
                    f[i][j] = f[i-1][j-1] + a;
                    pr[i][j] = 1;
                }
            }
            if (f[i-1][j] + b > f[i][j]) {
                f[i][j] = f[i-1][j] + b;
                pr[i][j] = 2;
            }
        }
    }

    FO(i,1,n+1) {
        int a, b, ind; tie(a,b,ind) = t[n-i];
        FO(j,0,i+1) {
            // take not an a
            g[i][j] = -1e9;
            if (j) {
                if (g[i-1][j-1] + b > g[i][j]) {
                    g[i][j] = g[i-1][j-1] + b;
                    pr2[i][j] = 2;
                }
            }
            if (g[i-1][j] > g[i][j]) {
                g[i][j] = g[i-1][j];
                pr2[i][j] = 1;
            }
        }
    }

    int bst = -1e9;
    int bi = -1;
    FO(i,p,n+1) {
        // we take the top i, p of them as a, i-p as b
        int s1 = f[i][p];
        //printf("f[%d][%d] = %d\n", i, p, f[i][p]);
        if (s-(i-p) >= 0 && s-(i-p) <= n-i) {
            int s2 = g[n-i][s-(i-p)];
            if (s1+s2 > bst) {
                bst = s1+s2;
                bi = i;
            }
        }
    }
    //printf("bi=%d\n", bi);
    int i = bi, j = p;
    while (i) {
        int pp = pr[i][j];
        //printf("i=%d, j=%d, pp=%d\n", i, j, pp);
        tp[i-1] = pp;
        if (pp == 1) {
            i--; j--;
        } else if (pp == 2) {
            i--;
        } else {
            assert(false);
        }
    }

    i = n-bi; j = s - (bi-p);
    //printf("j=%d, s=%d, bi=%d, p=%d\n", j, s, bi, p);
    while (i) {
        int pp = pr2[i][j];
        //printf("i=%d, j=%d, pp=%d\n", i, j, pp);
        tp[n-i] = pp == 2 ? 2 : 0;
        if (pp == 2) {
            i--; j--;
        } else if (pp == 1) {
            i--;
        } else {
            assert(false);
        }

    }

    printf("%d\n", bst);
    FO(i,0,n) if (tp[i] == 1) printf("%d ", get<2>(t[i]));
    printf("\n");
    FO(i,0,n) if (tp[i] == 2) printf("%d ", get<2>(t[i]));
    printf("\n");

    return 0;
}