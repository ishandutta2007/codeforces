#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

struct osmosis {
    multiset<ll> small;
    multiset<ll> big;
    ll smsmall;

    osmosis() {
        small.clear(); big.clear(); smsmall = 0;
    }

    void erase(ll x) {
        auto it = small.find(x);
        if (it != small.end()) {
            smsmall -= x;
            small.erase(it);
        } else {
            it = big.find(x);
            big.erase(it);
        }
    }

    ll smksmall(int k) {
        if (sz(small)+sz(big) < k) return 1e18;
        while (sz(small) < k) {
            ll x = *big.begin();
            big.erase(big.begin());
            small.insert(x);
            smsmall += x;
        }
        while (sz(small) > k) {
            ll x = *small.rbegin();
            small.erase(small.find(x));
            big.insert(x);
            smsmall -= x;
        }
        return smsmall;
    }
};

vector<int> path;
ll targ;

ll solve(vector<ll> x, int nl, int nr, int ip, bool genp) {
    assert(nl+nr == sz(x)-1);
    if (ip != 0 && nl == 0) return 1e18;
    if (ip == sz(x)-1) return 1e18;

    int wl = min(nl, ip);
    int wr = ip - wl;
    ll ans = (x[ip]-x[0]) * 2;
    nl -= wl; nr -= wr; x.erase(x.begin(),x.begin()+ip);
    assert(sz(x) >= 2);
    assert(nl+nr == sz(x)-1);
    if (nr == 0) return 1e18;

    if (genp) {
        // use wl lefts from ip
        for (int i = wl-1; i >= 0; i--) path.push_back(i);
        for (int i = wl; i < ip; i++) path.push_back(i);
    }

    vector<ll> dx;
    FO(i,0,sz(x)-1) dx.push_back(x[i+1]-x[i]);
    FO(i,0,sz(dx)) ans += dx[i];

    //printf("ans=%lld, nsp=%d\n", ans, nl);
    //FO(i,0,sz(dx)) printf("%lld ", dx[i]);
    //printf("\n");

    ll res = 1e18;

    osmosis m;
    FO(i,1,sz(dx)) m.big.insert(dx[i]);
    ll sufsm = 0;
    for (int i = sz(dx)-1; i >= 0; i--) {
        // take after i as suffix
        // that is sz(dx)-i-1 elements
        int hv = sz(dx)-i-1;
        int nd = nl-hv;
        if (nd >= 0) {
            res = min(res, ans + sufsm + 2*m.smksmall(nd));
            if (genp && res == targ) {
                vector<pair<ll,int> > v;
                FO(j,1,i+1) v.emplace_back(dx[j],j);
                sort(v.begin(),v.end());
                v.resize(nd);
                vector<int> u;
                for (auto p : v) u.push_back(p.second);
                FO(j,i+1,sz(dx)) u.push_back(j);
                sort(u.begin(), u.end());
                //for (int p : u) printf("%d ", p);
                //printf("\n");

                int lst = 0;
                for (int i = 0; i < sz(u); ) {
                    int j;
                    for (j = i; j < sz(u) && u[j]-u[i] == j-i; j++);
                    j--;
                    while (lst+1 < u[i]) path.push_back(ip+(++lst));
                    for (int k = u[j]+1; k >= u[i]; k--) {
                        path.push_back(ip+k);
                    }
                    lst = u[j]+1;
                    i = j+1;
                }
                while (lst < sz(dx)) path.push_back(ip+(++lst));
                return res;
            }
        }
        sufsm += dx[i];
        if (i) m.erase(dx[i]);
    }

    //printf("res=%lld\n", res);
    return res;
}

int n, l, s;
ll x[100005];

int main() {
    scanf("%d %d %d", &n, &l, &s); s--;
    FO(i,0,n) scanf("%lld", x+i);
    ll ans1 = solve(vector<ll>(x,x+n), l, n-1-l, s, false);
    FO(i,0,n) x[i] *= -1;
    reverse(x,x+n);
    ll ans2 = solve(vector<ll>(x,x+n), n-1-l, l, n-1-s, false);
    FO(i,0,n) x[i] *= -1;
    reverse(x,x+n);

    if (min(ans1,ans2) > 1e17) printf("-1\n");
    else {
        if (ans1 < ans2) {
            targ = ans1;
            solve(vector<ll>(x,x+n), l, n-1-l, s, true);
        } else {
            targ = ans2;
            FO(i,0,n) x[i] *= -1;
            reverse(x,x+n);
            solve(vector<ll>(x,x+n), n-1-l, l, n-1-s, true);
            FO(i,0,n-1) path[i] = n-1-path[i];
        }
        printf("%lld\n", targ);
        FO(i,0,n-1) printf("%d%c", 1+path[i], " \n"[i+2==n]);
    }
}