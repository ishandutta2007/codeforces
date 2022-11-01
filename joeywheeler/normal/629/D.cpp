#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll s[100005];
ll r[200005];
int n;

void u(int i, ll v) {
    for (r[i+=n]=v; i>1; i/=2) r[i/2] = max(r[i],r[i^1]);
}

ll q(int l, int r) {
    ll v = 0;
    for (l+=n,r+=n;l<r;l/=2,r/=2) {
        if (l&1) v = max(v,::r[l++]);
        if (r&1) v = max(v,::r[--r]);
    }
    return v;
}

pair<ll,int> o[100005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x,y; scanf("%d%d", &x, &y);
        s[i] = 1ll*x*x*y;
        o[i] = make_pair(1ll*x*x*y,-i);
    }
    sort(o,o+n);
    FO(z,0,n) {
        int i = -o[z].second;
        ll r = q(0,i) + s[i];
        u(i,r);
    }
    double ans = q(0,n) * acos(-1);
    printf("%.10lf\n", ans);
}