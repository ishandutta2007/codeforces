#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int k,e,o;

int main() {
    int n; scanf("%d%d", &n, &k);
    FO(i,0,n) {
        int x;
        scanf("%d", &x);
        if (x&1) o++;
        else e++;
    }
    if (e+o == k) {
        if (o%2) printf("Stannis\n");
        else printf("Daenerys\n");
    } else {
        int v = e-o;
        if (k%2) {
            if (v <= -k || (v < k && v%2 == 0)) {
                printf("Stannis\n");
            } else {
                printf("Daenerys\n");
            }
        } else {
            v = abs(v);
            if (v < k && v%2 == 1) {
                printf("Stannis\n");
            } else {
                printf("Daenerys\n");
            }
        }
    }
}