#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, s;
int a[200005];
int res;

int main() {
    scanf("%d %d", &n, &s); s--;
    FO(i,0,n) {
        scanf("%d", a+i);
        if (a[i] == 0 && i != s) {
            a[i] = n+5;
        }
        if (a[i] != 0 && i == s) {
            a[i] = 0;
            res++;
        }
    }
    sort(a,a+n);
    int mx = 0;
    for (int i = 0; i < n;) {
        if (a[i] <= mx) i++;
        else if (a[i] == mx+1) {
            mx++;
            i++;
        } else {
            n--;
            res++;
            mx++;
        }
    }
    printf("%d\n", res);
}