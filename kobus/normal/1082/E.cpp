#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 5;

int mn[N], v[N], ncp[N];

int main() {
    int n, c, nc = 0; scanf("%d %d", &n, &c);
    int resp = 0;
    for (int i=0;i<n;i++) {
        int a; scanf("%d", &a);
        if (a == c) nc++;
        else {
            mn[a] = min(mn[a], v[a] - (nc - ncp[a]));
            v[a] = (v[a] - (nc - ncp[a])) + 1;
            ncp[a] = nc;
            resp = max(resp, v[a] - mn[a]);
        }
    }
    printf("%d\n", resp + nc);
    return 0;
}