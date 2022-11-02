#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, q, a[300005];

struct pointseg {
    ll val[1200005], lim;
    void init (bool flag) {
        for(lim=1;lim<=n;lim<<=1);
        if(flag) {
            for(int i=1;i<=n;i++) {
                val[lim+i] = i;
            }
        }
    }
    void update (ll S, ll E, ll X) {
        S += lim; E += lim;
        while(S<=E) {
            if(S % 2 == 1) {val[S] += X; S++;}
            if(E % 2 == 0) {val[E] += X; E--;}
            S>>=1; E>>=1;
        }
    }
    ll query (ll P) {
        P += lim; ll ret = 0;
        while(P) {
            ret += val[P];
            P>>=1;
        }
        return ret;
    }
} ls, le, rs, re, val;

struct lazyseg {
    ll val[1200005], lazy[1200005], lim;
    void lazydown (ll P) {
        val[2*P] += lazy[P];
        lazy[2*P] += lazy[P];
        val[2*P+1] += lazy[P];
        lazy[2*P+1] += lazy[P];
        lazy[P] = 0;
    }
    void update (ll SS, ll SE, ll S, ll E, ll P, ll V){
        if(S <= SS && SE <= E) {
            val[P] += V; lazy[P] += V;
            return;
        }
        if(SE < S || E < SS) return;
        lazydown(P);
        ll mid = (SS+SE)/2;
        update(SS, mid, S, E, 2*P, V);
        update(mid+1, SE, S, E, 2*P+1, V);
        val[P] = max(val[2*P], val[2*P+1]);
    }
    void update (ll S, ll E, ll X) {
        update(1, n, S, E, 1, X);
    }
    ll query (ll SS, ll SE, ll S, ll E, ll P) {
        if(S <= SS && SE <= E) return val[P];
        if(SE < S || E < SS) return 0;
        lazydown(P);
        ll mid = (SS+SE)/2, ret = 0;
        ret = max(ret, query(SS, mid, S, E, 2*P));
        ret = max(ret, query(mid+1, SE, S, E, 2*P+1));
        return ret;
    }
    ll query (ll S, ll E) {
        return query(1, n, S, E, 1);
    }
} ans;

void update (ll S, ll E, ll X) {
    ll ax, ay, bx, by;
    if(S != 1) {
        ax = val.query(S-1);
        ay = val.query(S);
        if(ax > ay && ay + X >= ax) {
            ll tmp =  S - re.query(S), t2 = rs.query(S);
            re.update(S, t2, tmp);
            tmp = S - 1 - rs.query(S-1), t2 = re.query(S-1);
            rs.update(t2, S-1, tmp);
            ans.update(t2, S-1, tmp);
        }
    }
    if(E != n) {
        bx = val.query(E);
        by = val.query(E+1);
        if(by > bx && bx + X >= by) {
            ll tmp = E - le.query(E), t2 = ls.query(E);
            le.update(t2, E, tmp);
            tmp = E + 1 - ls.query(E+1), t2 = le.query(E+1);
            ls.update(E+1, t2, tmp);
            ans.update(E+1, t2, -tmp);
        }
    }
    if(S != 1 && ax >= ay && ay + X > ax) {
        ll tmp = le.query(S) - (S - 1), t2 = ls.query(S-1);
        le.update(t2, S-1, tmp);
        t2 = (tmp + S - 1); tmp = ls.query(S-1) - S;
        ls.update(S, t2, tmp);
        ans.update(S, t2, -tmp);
    }
    if(E != n && by >= bx && bx + X > by) {
        ll tmp = re.query(E) - (E + 1), t2 = rs.query(E+1);
        re.update(E+1, t2, tmp);
        t2 = (tmp + E + 1); tmp = rs.query(E+1) - E;
        rs.update(t2, E, tmp);
        ans.update(t2, E, tmp);
    }
    val.update(S, E, X);
}

int main()
{
    scanf("%lld",&n);
    ls.init(true); le.init(true);
    rs.init(true); re.init(true);
    val.init(false);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        update(i, i, a[i]);
    }
    scanf("%lld",&q);
    while(q--) {
        ll A, B, C;
        scanf("%lld%lld%lld",&A,&B,&C);
        update(A, B, C);
        printf("%lld\n",ans.query(1,n)+1);
    }
}