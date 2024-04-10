#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 4e18;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    ll f, T, t0;
    ll a1, p1, t1;
    ll a2, p2, t2;
    while (cin >> f >> T >> t0 >> a1 >> t1 >> p1 >> a2 >> t2 >> p2) {
        ll ans = INF;
        for (int it = 0; it < 2; it++) {
            for (ll cnt1 = 0; cnt1 * t1 <= T + t1; cnt1++) {
                ll packets1 = min(T / t1, cnt1 * a1);
                ll cans = cnt1 * p1;
                ll cf = f - packets1;
                ll cT = T - packets1 * t1;
                
                if (cf <= 0) {
                    ans = min(ans, cans);
                    continue;
                }

                if (cf * t0 <= cT) {
                    ans = min(ans, cans);
                    continue;
                }
                if (t0 <= t2) continue;

                ll fullBundles = cT / (t2 * a2) * a2;
                ll fullDownloaded = fullBundles + (cT - t2 * fullBundles) / t0;

                if (fullDownloaded < cf) {
                    ll mxPackets = cT / t2;
                    ll cDownloaded = mxPackets + (cT - t2 * mxPackets) / t0;
                    if (cDownloaded >= cf) {
                        ans = min(ans, cans + (cT / (t2 * a2) + 1) * p2);
                    } 
                    continue;
                }

                // find min k: a2*k + (cT - t2 * a2*k) / t0 >= cf
                // (cT + a2*k * (t0 - t2)) / t0 >= cf
                // cT + a2*k * (t0 - t2) >= cf * t0
                // a2*k * (t0 - t2) >= cf * t0 - cT
                // a2*k >= (cf * t0 - cT) / (t0 - t2)
                // k >= 
                ll k = (cf * t0 - cT + (t0 - t2 - 1)) / (t0 - t2);
                k = (k + a2 - 1) / a2;

                cans += k * p2;
                ans = min(ans, cans);
            }
            swap(t1, t2);
            swap(p1, p2);
            swap(a1, a2);
        }
        if (ans == INF) ans = -1;
        cout << ans << endl;
    }
    
    return 0;
}