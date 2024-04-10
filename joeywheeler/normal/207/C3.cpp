#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define f first
#define s second

#define M1 1000000007ll
#define M2 1000000009ll
#define B 137

#define N 100005

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ht;

struct BIT {
    ll v[N];

    ll q(int i) {
        //fprintf(stderr, "i=%d\n", i);
        ll r = 0;
        for (;i;i-=i&-i) r += v[i];
        return r;
    }

    void u(int i, ll r) {
        for (;i<N;i+=i&-i) v[i] += r;
    }
} b1, b2;

ht P[N];
int x[N][26], y[N][26];
int xd[N], yd[N];
int xp[N], yp[17][N];
int xw[N], yw[N];
ht xh[N], yh[N];
int ytx[N];
int n;
int s1, s2;
int op[N];
int no[N];
ll ans[N];
map<ht,int> mp;

ll fx(ll a, ll m) { return a >= m ? a-m : a; }

ht add(ht a, ht b) {
    return ht(fx(a.f+b.f,M1), fx(a.s+b.s,M2));
}

ht sub(ht a, ht b) {
    return ht(fx(a.f-b.f+M1,M1), fx(a.s-b.s+M2,M2));
}

ht mul(ht a, ht b) {
    return ht(a.f*b.f%M1, a.s*b.s%M2);
}

ht yhash(int i, int j) {
    // i is anc of j
    return mul(sub(yh[j],yh[i]),P[100004-yd[j]]);
}

// we cover [l,r] and we are l
int l[N], r[N], T;

void go(int i) {
    ++T;
    l[i] = T;
    FO(j,0,26) if (x[i][j]) go(x[i][j]);
    r[i] = T;
}

int main() {
    s1 = 1, s2 = 1;
    scanf("%d", &n);
    P[0] = {1,1};
    FO(i,1,N) P[i] = mul(P[i-1], {B,B});
    mp[{0,0}] = 1;
    xw[1] = yw[1] = 1;
    no[1] = 1;
    FO(i,0,n) {
        int t, pr; char ch;
        scanf("%d%d %c", &t, &pr, &ch);
        op[i] = t;

        if (t == 1) {
            pr = xw[pr];
            s1++;
            if (!x[pr][ch-'a']) {
                xp[s1] = pr;
                xd[s1] = xd[pr]+1;
                x[pr][ch-'a'] = s1;
                xh[s1] = add(mul(xh[pr], {B,B}), {ch,ch});
                mp[mul(xh[s1],P[100004-xd[s1]])] = s1;
            }
            xw[s1] = x[pr][ch-'a'];
        } else {
            pr = yw[pr];
            s2++;
            if (!y[pr][ch-'a']) {
                yp[0][s2] = pr;
                yd[s2] = yd[pr]+1;
                y[pr][ch-'a'] = s2;
                yh[s2] = add(yh[pr], mul(P[yd[pr]],{ch,ch}));
            }
            yw[s2] = y[pr][ch-'a'];
        }
    }
    FO(i,1,17) FO(j,1,s2+1) if (yw[j] == j) {
        yp[i][j] = yp[i-1][yp[i-1][j]];
    }

    FO(j,1,s2+1) {
        if (yw[j] == j) {
            int cp = j;
            for (int i = 16; i >= 0; i--) {
                int np = yp[i][cp];
                if (np && mp.count(yhash(np,j))) cp = np;
            }
            ytx[j] = mp[yhash(cp,j)];
        } else ytx[j] = ytx[yw[j]];
    }
    go(1);

    ll res = 1;

    b2.u(l[1],1); b2.u(r[1]+1,-1);
    b1.u(l[1],1);

    s1 = 1, s2 = 1;
    FO(Z,0,n) {
        int t = op[Z];
        if (t == 1) {
            s1++;
            // add s1
            int i = xw[s1];
            res += b1.q(r[i]) - b1.q(l[i]-1);
            b2.u(l[i],1); b2.u(r[i]+1,-1);
        } else {
            s2++;
            // add s2
            int i = ytx[s2];
            res += b2.q(l[i]);
            b1.u(l[i],1);
        }
        printf("%lld\n", res);
    }
}