#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int a, b;

int main() {
    scanf("%d%d", &a, &b);
    int m = min(a,b); a-=m; b-=m;
    printf("%d %d\n", m, (a+b)/2);
}