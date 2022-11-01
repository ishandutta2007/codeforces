#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
#define x first
#define y second

int n;
pair<ll,ll> p[100005];

ll sq(ll a) {
    return a*a;
}
ll dst(pair<ll,ll> a, pair<ll,ll> b) {
    return sq(a.x-b.x) + sq(a.y-b.y);
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%lld %lld", &p[i].x, &p[i].y);
    }
    int b = 1;
    FO(i,1,n) {
        if (dst(p[i],p[0]) < dst(p[b],p[0])) b = i;
    }
    ll x1 = p[0].x, y1 = p[0].y;
    ll x2 = p[b].x, y2 = p[b].y;
    ll A = y2-y1;
    ll B = x1-x2;
    ll C = x2*y1-x1*y2;
    int b2 = -1;
    ll bv;
    FO(i,0,n) {
        ll v = A * p[i].x + B * p[i].y + C;
        v = abs(v);
        if (v) {
            if (b2 == -1 || v < bv) {
                bv = v;
                b2 = i;
            }
        }
    }
    printf("%d %d %d\n", 1, b+1, b2+1);
}