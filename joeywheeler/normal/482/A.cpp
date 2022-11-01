#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int l = 0, r = n+1;
    int cur = 0;
    FO(i,0,k-1) {
        if (cur == 0) {
            printf("%d ", ++l);
            cur = 1;
        } else {
            printf("%d ", --r);
            cur = 0;
        }
    }
    if (cur == 0) {
        while (l+1 != r) {
            printf("%d ", ++l);
        }
    } else {
        while (r-1 != l) {
            printf("%d ", --r);
        }
    }
}