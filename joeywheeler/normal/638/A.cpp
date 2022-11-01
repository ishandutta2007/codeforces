#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int n, a; scanf("%d%d", &n, &a);
    if (a%2 == 1) {
        printf("%d\n", (a+1)/2);
    } else {
        printf("%d\n", (n-a+2)/2);
    }
}