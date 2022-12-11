#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;

int main()
{

    ios_base::sync_with_stdio(false);
    int n, d, h;
    cin >> n >> d >> h;
    if (d > 2 * h) {
        cout << "-1\n";
        return 0;
    }

    vector<pii> v;

    if (d == h) {
        for (int i = 1; i <= h; ++i) {
            v.pb(mp(i, i + 1));
        }
        if (sz(v) == n - 1) {
            for (pii& p : v) {
                cout << p.first << " " << p.second << "\n";
            }
            return 0;
        }
        if (h == 1) {
            cout << "-1\n";
            return 0;
        }
        for (int i = h + 2; i <= n; ++i) {
            v.pb(mp(2, i));
        }
        for (pii& p : v) {
            cout << p.first << " " << p.second << "\n";
        }
        return 0;
    }

    for (int i = 1; i <= h; ++i) {
        v.pb(mp(i, i + 1));
    }
    int prev = 1;
    for (int i = h; i < d; ++i) {
        v.pb(mp(prev, i + 2));
        prev = i + 2;
    }

    if (sz(v) > n - 1) {
        cout << "-1\n";
        return 0;
    }
    for (int i = prev + 1; i <= n; ++i) {
        v.pb(mp(1, i));
    }

    for (pii& p : v) {
        cout << p.first << " " << p.second << "\n";
    }

}