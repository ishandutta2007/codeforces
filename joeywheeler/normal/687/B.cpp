#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    int o = 1;
    FO(i,0,n) {
        int c; scanf("%d", &c);
        c = __gcd(c,k);
        o = o / __gcd(c,o) * c;
    }
    printf(o == k ? "Yes\n" : "No\n");
}