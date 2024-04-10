#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n;
ll x, y;
vector<int> u[200005];
int r = 0;

bool go(int i, int p) {
    int nc = 0;
    for (int j : u[i]) if (j != p) {
        bool t = go(j,i);
        if (t) {
            r++;
        } else {
            nc++;
        }
    }
    if (nc == 0 || nc == 1) return false;
    else {
        r += nc-2;
        return true;
    }
}

int main() {
    scanf("%d %lld %lld", &n, &x, &y);
    FO(i,0,n-1) {
        int a, b; scanf("%d%d", &a, &b);
        u[a].push_back(b);
        u[b].push_back(a);
    }
    int mxd = 0;
    FO(i,1,n+1) mxd = max(mxd, sz(u[i]));
    if (x >= y) {
        if (mxd == n-1) {
            printf("%lld\n", (n-2) * y + x);
        } else {
            printf("%lld\n", (n-1) * y);
        }
        return 0;
    }
    go(1,0);
    printf("%lld\n", r * y + (n-1-r) * x);
}