#include<bits/stdc++.h>
#define MAX   100100
#define MAXP   111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ll ceil(ll p,ll q) {
    return (p/q+(p%q>0));
}
class ConvexHull {
    private:
    struct segment {
        ll x,a,b;
        segment() {
            x=0;a=0;b=0;
        }
        segment(ll _x,ll _a,ll _b) {
            x=_x;a=_a;b=_b;
        }
        ll val(void) const {
            return (a*x+b);
        }
    };
    int l,r,nl;
    vector<segment> v;
    public:
    ConvexHull() {
        l=0;r=0;nl=0;
    }
    ConvexHull(int n) {
        l=0;r=0;nl=0;
        v=vector<segment>(2*n+7);
    }
    void reset(void) {
        nl=0;
    }
    void addline(ll a,ll b) {
        nl++;
        if (nl<2) {
            l=0;
            r=1;
            v[0]=segment(0,a,b);
            v[1]=segment(MAX,a,b);
            return;
        }
        int i;
        for (i=r;i>=l;i=i-1) if (v[i].val()<a*v[i].x+b) break;
        if (i==r) return;
        if (i<l) {
            l=0;
            r=1;
            v[0]=segment(0,a,b);
            v[1]=segment(MAX,a,b);
            return;
        }
        ll x=ceil(b-v[i].b,v[i].a-a);
        v[i+1]=segment(x,a,b);
        v[i+2]=segment(MAX,a,b);
        r=i+2;
    }
    ll getmin(ll x) {
        assert(x<MAX);
        while (l<r && v[l+1].x<=x) l++;
        return (v[l].a*x+v[l].b);
    }
};
ll a[MAX],s[MAX];
ll f[MAX][MAXP];
int d[MAX];
int n,m,p;
ConvexHull CH;
void init(void) {
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&p);
    if (p>m) p=m;
    FOR(i,2,n) {
        int v;
        scanf("%d",&v);
        d[i]=d[i-1]+v;
    }
    FOR(i,1,m) {
        int h,t;
        scanf("%d",&h);
        scanf("%d",&t);
        a[i]=d[h]-t;
    }
    sort(a+1,a+m+1);
    FOR(i,1,m) s[i]=s[i-1]+a[i];
}
void optimize(void) {
    CH=ConvexHull(m);
    FOR(i,1,m) f[i][1]=s[i]-i*a[1];
    FOR(j,2,p) {
        CH.reset();
        ii prev;
        FOR(i,j,m) {
            ii cur=ii(-a[i],f[i-1][j-1]-s[i-1]+(i-1)*a[i]);
            if (i==j || cur<prev) {
                CH.addline(cur.fi,cur.se);
                prev=cur;
            }
            f[i][j]=CH.getmin(i)+s[i];
        }
    }
    cout << f[m][p];
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    optimize();
    return 0;
}