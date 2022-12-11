#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const ll inf = 2e9 + 1;

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    ll lf = 0, rg = inf;
    while (lf < rg - 1) {
        ll md = (lf + rg) / 2;
        ll extra = 0;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            ll val = b[i] - md * a[i];
            if (val < 0) {
                extra += abs(val);
                if (extra > k) {
                    break;
                    flag = false;
                }
            }
        }
        if (extra <= k && flag) {
            lf = md;
            //cout << md << " " << b[0] << " " << a[0] << " " << extra << " " << k << "\n";
        } else {
            rg = md;
        }
    }

    cout << lf << "\n";

}