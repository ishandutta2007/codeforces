#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int a[1005], b[1005];
int n;

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i);
    FO(i,0,n) scanf("%d", b+i);
    int r = 0;
    FO(i,0,n) {
        int x = 0, y = 0;
        FO(j,i,n) {
            x |= a[j];
            y |= b[j];
            r = max(r, x+y);
        }
    }
    printf("%d\n", r);
}