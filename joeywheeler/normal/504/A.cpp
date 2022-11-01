#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int d[100005], s[100005];

int main() {
    int n; scanf("%d", &n);
    FO(i,0,n) scanf("%d %d", d+i, s+i);
    queue<int> q;
    long long dd=0;
    FO(i,0,n) {
        if (d[i] == 1) q.push(i);
        dd += d[i];
    }
    printf("%lld\n", dd/2);
    while (!q.empty()) {
        int f = q.front(); q.pop();
        if (d[f] == 1) {
            int p = s[f];
            d[p]--; s[p] ^= f;
            printf("%d %d\n", f, p);
            if (d[p] == 1) q.push(p);
        }
    }
}