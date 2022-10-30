#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int w[3], h[3];
char l[3];

int main() {
    FO(i,0,3) scanf("%d%d", w+i, h+i);
    FO(i,0,3) l[i] = 'A'+i;
    FO(Z,0,1000000) {
        FO(j,0,3) if (rand()&1) swap(w[j],h[j]);
        FO(j,1,3) {
            int k = rand()%j;
            swap(w[j],w[k]);
            swap(h[j],h[k]);
            swap(l[j],l[k]);
        }
        if (h[1] != h[2]) continue;
        if (w[0] != w[1]+w[2]) continue;
        if (w[0] != h[0]+h[1]) continue;
        int n = w[0];
        printf("%d\n", n);
        FO(y,0,h[0]) {
            FO(x,0,w[0]) printf("%c", l[0]);
            printf("\n");
        }
        FO(y,0,h[1]) {
            FO(x,0,n) printf("%c", x<w[1] ? l[1] : l[2]);
            printf("\n");
        }
        return 0;
    }
    FO(Z,0,1000000) {
        FO(j,0,3) if (rand()&1) swap(w[j],h[j]);
        FO(j,1,3) {
            int k = rand()%j;
            swap(w[j],w[k]);
            swap(h[j],h[k]);
            swap(l[j],l[k]);
        }
        if (w[0] != w[1] || w[1] != w[2]) continue;
        if (h[0]+h[1]+h[2] != w[0]) continue;
        int n = w[0];
        printf("%d\n", n);
        FO(y,0,h[0]) {
            FO(x,0,w[0]) printf("%c", l[0]);
            printf("\n");
        }
        FO(y,0,h[1]) {
            FO(x,0,w[0]) printf("%c", l[1]);
            printf("\n");
        }
        FO(y,0,h[2]) {
            FO(x,0,w[0]) printf("%c", l[2]);
            printf("\n");
        }
        return 0;
    }
    printf("-1\n");
}