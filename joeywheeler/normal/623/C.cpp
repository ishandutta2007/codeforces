#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define inf int(1e9)

using namespace std;

typedef long long ll;
#define x first
#define y second

ll sq(ll x) {
    return x*x;
}

pair<int,int> p[100005];
int n;

vector<tuple<int,int,int> > f, g;

void go(vector<tuple<int,int,int> > &v, bool z) {
    int mx = -inf, mn = inf;
    FO(i,0,n) if (p[i].x < 0 || (z && p[i].x == 0)) {
        if (i == 0 || p[i].x != p[i-1].x) {
            v.emplace_back(-p[i].x, mn, mx);
        }
        mn = min(mn,p[i].y);
        mx = max(mx,p[i].y);
    }
}

vector<tuple<int,int,int> > ff, gg;

pair<int,int> tv[10];
int stv;

ll calc(tuple<int,int,int> a, tuple<int,int,int> b) {
    stv = 0;

    int x, mny, mxy;
    tie(x,mny,mxy) = a;
    x *= -1;

    if (abs(x) != inf) tv[stv++]=make_pair(x,0);
    if (abs(mny) != inf) tv[stv++]=make_pair(0,mny);
    if (abs(mxy) != inf) tv[stv++]=make_pair(0,mxy);

    tie(x,mny,mxy) = b;

    if (abs(x) != inf) tv[stv++]=make_pair(x,0);
    if (abs(mny) != inf) tv[stv++]=make_pair(0,mny);
    if (abs(mxy) != inf) tv[stv++]=make_pair(0,mxy);

    ll csqd = 0;
    FO(i,0,stv) FO(j,0,stv) {
#define p1 tv[i]
#define p2 tv[j]
        csqd = max(csqd, sq(p1.x-p2.x) + sq(p1.y-p2.y));
    }

    return csqd;
}

// floor . sqrt
ll rt(ll x) {
    if (x < 0) return -1;
    ll d = floor(sqrt(x));
    ll a = 0;
    for (a = max(d-2,0ll); a*a <= x; a++);
    return a-1;
}

bool can(ll sqd) {
    ff.clear(); gg.clear();
    for (auto t : f) {
        if (calc(t, make_tuple(-inf, inf, -inf)) <= sqd) ff.push_back(t);
    }
    for (auto t : g) {
        if (calc(t, make_tuple(-inf, inf, -inf)) <= sqd) gg.push_back(t);
    }

    for (auto t : ff) {
        int x, mny, mxy;
        tie(x,mny,mxy) = t;
        // (ox+x)^2 <= sqd
        // ox <= rt(sqd)-x


        ll mxx = rt(sqd)-x;
        //printf("%lld, %lld\n", sqd, rt(sqd));
        //printf("x=%d, mxx=%lld\n", x, mxx);

        if (abs(mny) != inf) {
            // x <= rt(sqd - sq(mny))
            mxx = min(mxx, rt(sqd - sq(mny)));
        }
        if (abs(mxy) != inf) {
            // x <= rt(sqd - sq(mxy))
            mxx = min(mxx, rt(sqd - sq(mxy)));
        }

        ///printf("x=%d, mxx=%lld\n", x, mxx);

        int j = lower_bound(gg.begin(), gg.end(), make_tuple(mxx+1, -inf-1, -inf-1)) - gg.begin();
        j--;
        if (j >= 0 && calc(t, gg[j]) <= sqd) return true;
    }
    return false;
}

ll ans;

void spec() {
    int mx = -inf, mn = inf;
    FO(i,0,n) if (p[i].x > 0) {
        mn = min(mn,p[i].y);
        mx = max(mx,p[i].y);
    }

    int mxx = -inf;
    FO(i,0,n) if (p[i].x <= 0) mxx = max(mxx, p[i].x);

    FO(i,0,n) if (p[i].x <= 0) {
        int mnx = p[i].x;
        ll csqd = calc(make_tuple(mnx, mn, mx), make_tuple(-mxx, mn, mx));

        ans = min(ans, csqd);

        mn = min(mn,p[i].y);
        mx = max(mx,p[i].y);
    }
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d %d", &p[i].x, &p[i].y);

    // all on y
    int mny = inf, mxy = -inf;
    FO(i,0,n) mny = min(mny, p[i].y);
    FO(i,0,n) mxy = max(mxy, p[i].y);
    ans = sq(mxy-mny);

    sort(p,p+n);
    spec();
    go(f,false);
    reverse(p,p+n);
    FO(i,0,n) p[i].x *= -1;
    spec();
    go(g,true);

    sort(f.begin(),f.end());
    sort(g.begin(),g.end());

    ll s = 0, e = ans-1, b = ans;
    while (s <= e) {
        ll md = (s+e)/2;
        if (can(md)) {
            b = md;
            e = md-1;
        } else {
            s = md+1;
        }
    }
    printf("%lld\n", b);
}