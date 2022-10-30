#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int lp[200005], w[200005];
int d[200005];
int n;

int a[200005];

int main() {
    scanf("%d", &n);
    FO(i,1,n+1) scanf("%d", a+i);
    FO(i,2,n+1) lp[i] = i-1, w[i] = 1;
    for (int k = 2; k < n; k++) {
        for (int i = 1; k*(i-1)+2 <= n; i++) {
            int f = k*(i-1)+2;
            int l = k*i+1;
            l = min(l, n);
            while (lp[f] != i && f <= l) {
                if (a[f] < a[lp[f]]) {
                    d[w[f]]++;
                    d[k]--;
                }
                lp[f] = i;
                w[f] = k;

                f++;
            }
            while (lp[l] != i && l >= f) {
                if (a[l] < a[lp[l]]) {
                    d[w[l]]++;
                    d[k]--;
                }
                lp[l] = i;
                w[l] = k;

                l--;
            }
        }
    }
    FO(i,2,n+1) {
        if (a[i] < a[lp[i]]) {
            d[w[i]]++;
        }
    }
    FO(i,2,n) d[i] += d[i-1];
    FO(i,1,n) printf("%d%c", d[i], " \n"[i+1==n]);
}