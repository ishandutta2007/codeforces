#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
ll t[200005];
int n, k, b, c;

deque<ll> pq[5][5];
ll smx[5][5];

ll getmx(ll y) {
    ll mxx = -1; ll mxtm = -1;
    FO(i,0,5) {
        int ind = y%5;
        if (sz(pq[ind][i])) {
            ll tim = (y-pq[ind][i][0])/5 * b + (y-pq[ind][i][0])%5 * c;
            if (tim > mxtm) {
                mxtm = tim;
                mxx = pq[ind][i][0];
            }
        }
    }
    return mxx;
}

void fx(ll y) {
    while (1) {
        int np = 0;
        FO(i,0,5) np += sz(pq[y%5][i]);
        if (np <= k) {
            assert(np == k);
            break;
        }
        ll x = getmx(y);
        smx[y%5][x%5] -= x;
        pq[y%5][x%5].pop_front();
    }
}

ll eval(ll y) {
    ll res = 0;
    FO(i,0,5) {
        int rem = (y-i)%5;
        int nm = sz(pq[y%5][i]);
        res += (nm*y - smx[y%5][i] - nm*rem)/5 * b + nm*rem*c;
    }
    return res;
}

void add(ll tim) {
    FO(i,0,5) {
        smx[i][tim%5] += tim;
        pq[i][tim%5].push_back(tim);
    }
}

ll go() {
    ll res = 1e18;
    FO(i,0,n) {
        add(t[i]);
        if (i+1 >= k) {
            FO(j,0,6) if (i+1 == n || t[i]+j < t[i+1]) {
                fx(t[i]+j);
                res = min(res, eval(t[i]+j));
            }
        }
    }
    return res;
}

int main() {
    scanf("%d %d %d %d", &n, &k, &b, &c);
    b = min(b,5*c);

    FO(i,0,n) {
        scanf("%lld", t+i);
        t[i] += 1000000005;
    }
    sort(t,t+n);

    ll bst = go();
    printf("%lld\n", bst);
}