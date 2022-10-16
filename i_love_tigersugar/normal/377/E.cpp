#include<bits/stdc++.h>
#define MAX    200200
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
typedef pair<ll,ll> ii;
inline void minimize(ll &x,const ll &y) {
    if (x>y) x=y;
}
inline ll ceil(ll a,ll b) {
    assert(b!=0);
    if (b<0) {
        a=-a;
        b=-b;
    }
    assert(a>=0);
    return (a/b+(a%b>0));
}
class ConvexHull {
    private:
    struct segment {
        ll x,a,b;
        segment() {
            x=a=b=0;
        }
        segment(ll _x,ll _a,ll _b) {
            x=_x;a=_a;b=_b;
        }
        ll val(void) const {
            return (INF/a<x?INF:a*x+b);
        }
        bool operator < (const segment &x) const {
            return (val()<x.val());
        }
    };
    deque<segment> dq;
    public:
    ConvexHull(){}
    void addline(ll a,ll b) {
        if (dq.empty()) {
            dq.push_back(segment(0,a,b));
            dq.push_back(segment(INF/a,a,b));
            return;
        }
        int sz=dq.size();
        while (!dq.empty() && dq.back().val()<=segment(dq.back().x,a,b).val()) dq.pop_back();
        if (dq.size()==sz) return;
        if (dq.empty()) {
            dq.push_back(segment(0,a,b));
            dq.push_back(segment(INF/a,a,b));
            return;
        }
        ll x=ceil(dq.back().b-b,a-dq.back().a);
        dq.push_back(segment(x,a,b));
        dq.push_back(segment(INF/a,a,b));
    }
    ii query(ll req,ll prev) {
        while (dq.size()>1 && dq[1].x<=prev) dq.pop_front();
        int p=upper_bound(dq.begin(),dq.end(),segment(req,1,0))-dq.begin();
        if (p==0) {
            ll a=dq[p].a;
            ll b=dq[p].b;
            return (ii(prev,a*prev+b));
        }
        ll a=dq[p-1].a;
        ll b=dq[p-1].b;
        ll x=ceil(req-b,a);
        return (x<dq[p].x?ii(x,a*x+b):ii(dq[p].x,dq[p].val()));
    }
};
ii a[MAX];
int n;
ll s;
ConvexHull CH;
void init(void) {
    cin >> n >> s;
    FOR(i,1,n) cin >> a[i].fi >> a[i].se;
}
void filter(void) {
    sort(a+1,a+n+1);
    vector<ii> v;
    FOR(i,1,n) if (i==1 || a[i].fi>a[i-1].fi) v.push_back(a[i]);
    n=v.size();
    REP(i,n) a[i+1]=v[i];
    v.clear();
    ll minv=INF;
    FORD(i,n,1) if (a[i].se<minv) {
        v.push_back(a[i]);
        minv=a[i].se;
    }
    n=v.size();
    reverse(v.begin(),v.end());
    REP(i,n) a[i+1]=v[i];
}
void process(void) {
    ll res=INF;
    ii prev=ii(0,0);
    FOR(i,1,n) {
        CH.addline(a[i].fi,prev.se-a[i].fi*prev.fi-a[i].se);
        minimize(res,CH.query(s,prev.fi).fi);
        if (i<n) prev=CH.query(a[i+1].se,prev.fi);
    }
    cout << res;
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    filter();
    process();
    return 0;
}