#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int a[500000];

int main() {
    scanf("%d", &n);
    long long res = 0;
    int mn = 1e9+10;
    FO(i,0,n) {
        scanf("%d", a+i);
        mn = min(mn,a[i]);
    }
    FO(i,0,n) {
        a[i] -= mn;
        res += mn;
        a[i+n] = a[i];
    }
    int rn = 0;
    int tmp = 0;
    FO(i,0,2*n) {
        if (a[i] == 0) {
            rn = 0;
        } else {
            rn++;
        }
        tmp = max(tmp, rn);
    }
    printf("%lld\n", res+tmp);
}