#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int inf = 1e9;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a[3], b[3];
    for (int i = 0; i < 3; ++i) {
        cin >> a[i] >> b[i];
    }

    int ans = inf;
    int optx, opty;

    for (int x = 0; x <= 1000; ++x) {
        for (int y = 0; y <= 1000; ++y) {
            int val = 1;
            for (int i = 0; i < 3; ++i) {
                val += abs(a[i] - x) + abs(b[i] - y);
            }
            if (val < ans) {
                ans = val;
                optx = x, opty = y;
            }
        }
    }

    cout << ans << "\n";
    vector<pii> vct;

    for (int i = 0; i < 3; ++i) {
        int x = optx, y = opty;
        vct.pb({x, y});
        while (y != b[i]) {
            if (y > b[i]) {
                --y;
            } else {
                ++y;
            }
            vct.pb({x, y});
        }
        while (x != a[i]) {
            if (x > a[i]) {
                --x;
            } else {
                ++x;
            }
            vct.pb({x, y});
        }
    }

    sort(all(vct));
    vct.resize(unique(all(vct)) - vct.begin());
    for (int i = 0; i < sz(vct); ++i) {
        cout << vct[i].first << " " << vct[i].second << "\n";
    }

}