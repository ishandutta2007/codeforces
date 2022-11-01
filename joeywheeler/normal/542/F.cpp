#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, T;
pair<int,int> o[1005];
int cache[1005][2005];

int mul(int l, int c) {
    if (c == n-1) return l;
    else {
        int d = o[c+1].first-o[c].first;
        if (d >= 13) return 2000;
        else return min(2000, l*(1<<d));
    }
}

int f(int c, int l) {
    int &res = cache[c][l];
    if (res != -1) return res;
    if (c == n) return res = 0;

    res = 0;
    // don't take
    res = max(res, f(c+1, mul(l,c)));

    if (l) res = max(res, f(c+1, mul(l-1,c)) + o[c].second);

    return res;
}

int main() {
    scanf("%d %d", &n, &T);
    FO(i,0,n) {
        scanf("%d %d", &o[i].first, &o[i].second);
        o[i].first = T-o[i].first;
    }
    sort(o,o+n);
    memset(cache, -1, sizeof cache);
    int d = o[0].first;
    int l = d>=13 ? 2000 : min(2000,1<<d);
    printf("%d\n", f(0,l));
}