#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, a, b;

int main() {
    scanf("%d%d%d", &n, &a, &b); a--;
    int res = ((a+b)%n+n)%n;
    printf("%d\n", res+1);
}