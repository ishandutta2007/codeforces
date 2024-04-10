#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int o[2], p;
int n, q;

int main() {
    scanf("%d%d", &n, &q);
    FO(z,0,q) {
        int T; scanf("%d", &T);
        if (T == 2) {
            p = !p;
            swap(o[0],o[1]);
        } else {
            int x; scanf("%d", &x);
            x += 5*n;
            x %= n;
            x = (n-x)%n;
            if (x % 2 == 0) {
                o[0] += x/2;
                o[1] += x/2;
            } else {
                int a = o[0], b = o[1];
                o[0] = b + x/2;
                o[1] = a + x/2 + 1;
                p = !p;
            }
            o[0] %= n/2;
            o[1] %= n/2;
        }
    }
    FO(i,0,n) {
        if (i%2 == 0) {
            printf("%d", (i+2*o[0]+p) % n + 1);
        } else {
            printf("%d", (i+2*o[1]-1+!p+n) % n + 1);
        }
        printf("%c", " \n"[i+1==n]);
    }
}