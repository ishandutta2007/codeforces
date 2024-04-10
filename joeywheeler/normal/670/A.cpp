#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int m = 0, k = 0;
    FO(i,0,n) {
        if ((i%7) < 2) m++;
        if ((i%7) >= 5) k++;
    }
    printf("%d %d\n", k, m);
}