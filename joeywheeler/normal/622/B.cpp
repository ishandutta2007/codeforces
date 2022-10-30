#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int h, m, a; scanf("%d %*c %d %d", &h, &m, &a);
    m += a;
    h += m/60;
    m %= 60;
    h %= 24;
    printf("%02d:%02d\n", h, m);
}