#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char c[105][105];

int main() {
    int n;
    scanf("%d", &n);
    FO(i,0,n) {
        scanf(" %s", c[i]);
    }
    int res = 0;
    FO(y,0,n) {
        int i = 0;
        FO(x,0,n) i += c[y][x] == 'C';
        res += i*(i-1)/2;
    }
    FO(x,0,n) {
        int i = 0;
        FO(y,0,n) i += c[y][x] == 'C';
        res += i*(i-1)/2;
    }
    printf("%d\n", res);
}