#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        ll N, C, D; cin >> N >> C >> D;
        vector<ll> a(max(N, D) + 2);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<ll>());
        ll tot = 0;
        for (int i = 0; i < min(N, D); ++i){
            tot += a[i];
        }
        if (tot >= C){
            cout << "Infinity" << '\n';
            continue;
        }
        vector<ll> psa(D+2);
        for (int i = 1; i <= D+1; ++i){
            psa[i] = psa[i-1] + a[i-1];
            // cout << psa[i];
        }
        a[0] = 0;
        ll lo = 0, hi = D;
        bool good = 0;
        while (lo < hi){
            ll mi = (lo + hi + 1) >> 1;
            ll tot = 0;
            ll fulls = D / mi;
            ll some = D % mi;
            // fulls * a[mi+1] + a[some+1]
            double test = 1.0 * fulls * psa[mi] + psa[some];
            // cout << test << " ";
            // cout << mi << " " << fulls << " " << some << '\n';
            if (test >= 1e18) lo = mi, good = 1;
            else{
                ll x = fulls * psa[mi] + psa[some];
                if (x >= C) lo = mi, good = 1;
                else hi = mi - 1;
            }
        }
        if (good == 0) cout << "Impossible" << '\n';
        else cout << lo-1 << '\n';
    }
}