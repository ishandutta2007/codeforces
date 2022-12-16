#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

#define pb push_back
#define mp make_pair

#define MAXN 100'010

int l, n;
int a[MAXN];

bool poss(int mn, int mx) {
    if (mn > mx) return false;
    int lb = 0;
    int ub = 0;
    rep(i, 0, n) {
        int nlb = lb+mn;
        nlb = max(nlb, a[i]);
        int nub = ub+mx;
        if (i != n-1) nub = min(nub, a[i+1]);
        else nub = min(nub, l);
        lb = nlb;
        ub = nub;
        if (lb > ub) return false;
    }
    //cout << mn << ' ' << mx << ' ' << lb << ' ' << ub << endl;
    return ub == l;
}

vi retrieve(int mn, int mx) {
    pii bounds[n];
    int lb = 0;
    int ub = 0;
    rep(i, 0, n) {
        int nlb = lb+mn;
        nlb = max(nlb, a[i]);
        int nub = ub+mx;
        if (i != n-1) nub = min(nub, a[i+1]);
        else nub = min(nub, l);
        lb = nlb;
        ub = nub;
        bounds[i] = mp(lb, ub);
    }
    //cout << mn << ' ' << mx << ' ' << lb << ' ' << ub << endl;
    vi out;
    int curr = l;
    for (int i = n-1; i >= 1; i--) {
        
        int prevbound = bounds[i-1].second;
        //cout << i << ' ' << curr << ' ' << prevbound << endl;
        if (curr-prevbound >= mn) {
            out.pb(prevbound);
            curr = prevbound;
        } else {
            out.pb(curr-mn);
            curr -= mn;
        }
    }
    reverse(all(out));
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> l >> n;
    rep(i, 0, n) cin >> a[i];

    if (n == 1) {
        cout << "0 " << l << '\n';
        return 0;
    }


    int lo = -1;
    int hi = l+1;
    while (hi-lo>1) {
        int mid = (lo+hi)/2;

        if (poss(mid, l+1)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    int mnamt = lo;
    lo = -1;
    hi = l+1;
    while (hi-lo>1) {
        int mid = (lo+hi)/2;

        if (poss(mnamt, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    int mxamt = hi;

    //cout << mnamt << ' ' << mxamt << endl;

    vi out = retrieve(mnamt, mxamt);
    cout << 0 << ' ' << out[0] << '\n';
    rep(i, 0, sz(out)-1) {
        cout << out[i] << ' ' << out[i+1] << '\n';
    }
    cout << out[sz(out)-1] << ' ' << l << '\n';
}