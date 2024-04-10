#include <bits/stdc++.h>
using namespace std;

#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)

typedef long long ll;

inline ll ceildiv(ll a, ll b) {
    assert(b > 0);
    return (a + b - 1) / b;
}

const int N = 611111;

struct comp {
    int i;
    ll p;
    bool operator<(const comp& other) const {
        return p < other.p;
    }
};

comp comps[N];
int n;
bool subok(ll x1, ll x2, vector<int>& g1, vector<int>& g2) {
    for (int i = 0; i < n; i++) {
        // x1 / k <= comps[i].p
        // k >= x1 / comps[i].p
        ll j = i + ceildiv(x1, comps[i].p);
        if (j < n) {
            ll k = j + ceildiv(x2, comps[j].p);
            if (k <= n) {
                for (int t = i; t < j; t++) {
                    g1.push_back(comps[t].i);
                }
                for (int t = j; t < k; t++) {
                    g2.push_back(comps[t].i);
                }
                return true;
            }
        }
    }
    return false;
}

void solve() {
    ll x1, x2;
    sf("%d%lld%lld", &n, &x1, &x2);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &comps[i].p);
        comps[i].i = i + 1;
    }
    sort(comps, comps + n);
    vector<int> g1, g2;
    if (subok(x1, x2, g1, g2) || subok(x2, x1, g2, g1)) {
        printf("Yes\n%d %d\n", int(g1.size()), int(g2.size()));
        for (int i = 0; i < g1.size(); i++) {
            printf("%d%c", g1[i], " \n"[i == int(g1.size()) - 1]);
        }
        for (int i = 0; i < g2.size(); i++) {
            printf("%d%c", g2[i], " \n"[i == int(g2.size()) - 1]);
        }
    } else {
        printf("No\n");
    }
}

int main() {
    // for (int t = 0; t < 10; t++) solve();
    solve();
}