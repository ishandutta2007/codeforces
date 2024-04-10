#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())
#define mp make_pair
#define mt make_tuple

using namespace std;

int n, d[100005], pr[100005];

int main() {
    scanf("%d", &n);
    d[1] = 0;
    pr[0] = 1;
    fo(i,2,n+1) {
        int p; scanf("%d", &p);
        d[i] = d[p]+1;
        pr[d[i]] ^= 1;
    }
    int res = 0;
    fo(i,0,n+4) res += pr[i];
    printf("%d\n", res);
}