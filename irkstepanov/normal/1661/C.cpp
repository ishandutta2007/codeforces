#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int buben = 10;
const ll inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        ll maxx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            maxx = max(maxx, a[i]);
        }
        ll ans = inf;
        for (ll goal = maxx; goal <= maxx + buben; ++goal) {
            ll lf = -1, rg = inf;
            while (rg - lf > 1) {
                ll md = (lf + rg) >> 1;
                ll odd = (md + 1) / 2, even = md / 2;
                ll sum = 0;
                for (int i = 0; i < n; ++i) {
                    ll d = goal - a[i];
                    if (d & 1) {
                        --odd;
                        --d;
                    }
                    sum += d;
                }
                if (odd < 0 || sum > odd + even * 2) {
                    lf = md;
                } else {
                    rg = md;
                }
            }
            ans = min(ans, rg);
        }
        cout << ans << "\n";
    }

}