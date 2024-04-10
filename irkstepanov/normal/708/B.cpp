#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    ll x, y, z, t;
    cin >> x >> y >> z >> t;

    vector<ll> a, b;

    for (ll aa = 0; ; ++aa) {
        ll val = aa * (aa - 1) / 2;
        if (val == x) {
            a.pb(aa);
        } else if (val > x) {
            break;
        }
    }

    for (ll bb = 0; ; ++bb) {
        ll val = bb * (bb - 1) / 2;
        if (val == t) {
            b.pb(bb);
        } else if (val > t) {
            break;
        }
    }

    for (ll aa : a) {
        for (ll bb : b) {
            if (aa == 0 && bb == 0) {
                continue;
            }
            if (aa == 0) {
                if (x == 0 && y == 0 && z == 0) {
                    for (ll i = 0; i < bb; ++i) {
                        cout << '1';
                    }
                    cout << "\n";
                    return 0;
                } else {
                    continue;
                }
            }
            if (bb == 0) {
                if (y == 0 && z == 0 && t == 0) {
                    for (ll i = 0; i < aa; ++i) {
                        cout << '0';
                    }
                    cout << "\n";
                    return 0;
                } else {
                    continue;
                }
            }
            ll cnt = (aa + bb) * (aa + bb - 1) / 2;
            if (x + y + z + t != cnt) {
                continue;
            }
            ll k = y / bb;
            ll l = y % bb;
            string ans = "";
            for (ll i = 0; i < k; ++i) {
                ans += "0";
            }
            for (ll i = 0; i < bb - l; ++i) {
                ans += "1";
            }
            if (l) {
                ans += "0";
                for (int i = 0; i < l; ++i) {
                    ans += "1";
                }
            }
            while (sz(ans) < aa + bb) {
                ans += "0";
            }
            ll cnt_0 = 0, cnt_1 = 0;
            for (int i = 0; i < sz(ans); ++i) {
                if (ans[i] == '0') {
                    ++cnt_0;
                } else {
                    ++cnt_1;
                }
            }
            if (cnt_0 == aa && cnt_1 == bb) {
                cout << ans << "\n";
                return 0;
            }
        }
    }

    cout << "Impossible\n";

}