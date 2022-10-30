#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int x[200005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", x+i);
    sort(x,x+n);
    int l = n/2;
    int r = 2e9;
    FO(i,0,n) if (i+l < n) {
        r = min(r,x[i+l]-x[i]);
    }
    printf("%d\n", r);
}