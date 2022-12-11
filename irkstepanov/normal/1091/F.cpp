#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string s;
    cin >> s;

    ll xx = 0, yy = 0;
    ll ans = 0;

    ll grass = 0, water = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            ans += a[i] * 2;
            water += a[i];
            xx += a[i];
        } else if (s[i] == 'G') {
            if (xx >= a[i]) {
                ans += a[i];
                xx -= a[i];
                yy += a[i] * 2;
                ans += a[i];
            } else {
                ans += xx;
                ans += a[i] * 3 - xx * 2;
                yy += a[i] + xx;
                xx = 0;
            }
            grass += a[i];
        } else {
            ll rem = a[i];
            while (rem) {
                if (xx > 0) {
                    if (xx >= rem) {
                        xx -= rem;
                        ans += rem;
                        rem = 0;
                    } else {
                        ll t = xx;
                        xx -= t;
                        ans += t;
                        rem -= t;
                    }
                    continue;
                }

                if (yy > 0) {
                    if (yy >= rem) {
                        yy -= rem;
                        ans += rem * 2;
                        rem = 0;
                    } else {
                        ll t = yy;
                        yy -= t;
                        ans += t * 2;
                        rem -= t;
                    }
                    continue;
                }

                if (water) {
                    ans += rem * 3;
                    rem = 0;
                    break;
                }
                ans += rem * 5;
                rem = 0;
                break;
            }
            ans += a[i];
        }
    }

    cout << ans << "\n";

}