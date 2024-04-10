#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char t[200005];
int tl;
int m, b;
int c[26], cc[26];

int main() {
    int n; scanf("%d", &n);
    FO(i,0,n) scanf("%d", c+i);
    int odd = -1;
    FO(i,0,n) {
        if (c[i]&1) {
            if (odd == -1) odd = i;
            else odd = -2;
        }
    }
    if (odd == -2) {
        printf("0\n");
        FO(i,0,n) FO(j,0,c[i]) printf("%c", i+'a');
        printf("\n");
    } else if (odd != -1) {
        int l = c[0];
        FO(i,0,n) l = __gcd(l,c[i]);
        printf("%d\n", l);
        FO(z,0,l) {
            FO(i,0,n) if (i != odd) FO(j,0,c[i]/l/2) printf("%c", i+'a');
            FO(i,0,n) if (i == odd) FO(j,0,c[i]/l) printf("%c", i+'a');
            for (int i = n-1; i >= 0; i--) if (i != odd) FO(j,0,c[i]/l/2) printf("%c", i+'a');
        }
        printf("\n");
    } else {
        int l = c[0];
        FO(i,0,n) l = __gcd(l,c[i]);
        printf("%d\n", l);
        FO(z,0,l) {
            FO(i,0,n) {
                int k = c[i]/l;
                if (k%2 == 0) cc[i] = k;
                else {
                    if (z%2 == 0) cc[i] = 2*k;
                    else cc[i] = 0;
                }
            }
            FO(i,0,n) FO(j,0,cc[i]/2) t[tl++] = i+'a';
            for (int i = n-1; i >= 0; i--) FO(j,0,cc[i]/2) t[tl++] = i+'a';
        }
        t[tl] = 0;
        printf("%s\n", t);
    }
}