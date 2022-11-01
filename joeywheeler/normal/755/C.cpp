#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int l[10005];

int gl(int i) {
    return i==l[i]?i:l[i]=gl(l[i]);
}

int main() {
    int n;
    scanf("%d", &n);
    FO(i,0,n) l[i] = i;
    FO(i,0,n) {
        int p;
        scanf("%d", &p); p--;
        l[gl(i)] = gl(p);
    }
    int ans = 0;
    FO(i,0,n) if (gl(i) == i) ans++;
    printf("%d\n", ans);
}