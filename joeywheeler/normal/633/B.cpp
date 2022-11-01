#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int f(int n) {
    int r = 0;
    for (int i = 5; i <= n; i *= 5) r += n/i;
    return r;
}

int main() {
    int m;
    scanf("%d", &m);
    vector<int> v;
    for (int i = 1; ; i++) {
        int x = f(i);
        if (x > m) break;
        if (x == m) v.push_back(i);
    }
    printf("%d\n", sz(v));
    for (int x : v) printf("%d ", x);
    printf("\n");
}