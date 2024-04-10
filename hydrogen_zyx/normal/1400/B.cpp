#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t, n;
    cin >> t;
    while (t--) {
        ll cs, cw, s, w, p, f;
        cin >> p >> f >> cs >> cw >> s >> w;
        if (s > w) {
            swap(s, w);
            swap(cs, cw);
        }
        ll mmax = 0;
        for (ll i = 0; i <= cw; i++) {
            if (i * w > p) continue;
            ll ccs = cs, ccw = cw;
            ll pp = p, ff = f;
            pp -= i * w;
            ccw -= i;
            ll cnt = i;
            ll geshu = min(ccs, pp / s);
            pp -= geshu * s;
            cnt += geshu;
            ccs -= geshu;
            geshu = min(ccs, ff / s);
            ccs -= geshu;
            ff -= geshu * s;
            cnt += geshu;
            geshu = min(ccw, ff / w);
            cnt += geshu;
            mmax = max(mmax, cnt);
        }
        cout << mmax << endl;
    }
}