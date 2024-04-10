#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd "\n"; return 0;
#define all(v) v.begin(), v.end()
#define double long double

using namespace std;

const int MAXN = 1e5;
const int INF = 1e10;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    pr<pr<double, double>, pr<double, double>> gg;
    cin >> gg.fs.fs >> gg.fs.sc >> gg.sc.fs >> gg.sc.sc;
    vc<pr<double, double>> tek;
    for (int i = 0; i < n; i++) {
        double a, b, c, d;
        double ans1, ans2, ans3, ans4;
        cin >> a >> b >> c >> d;
        if (c == 0) {
            if (gg.fs.fs < a && a < gg.sc.fs) {
                ans1 = 0;
                ans2 = INF;
            } else {
                cout << -1 << endd;
            }
        } else {
            ans1 = (gg.fs.fs - a) / c;
            ans2 = (gg.sc.fs - a) / c;
        }
        if (d == 0) {
            if (gg.fs.sc < b && b < gg.sc.sc) {
                ans3 = 0;
                ans4 = INF;
            } else {
                cout << -1 << endd;
            }
        } else {
            ans3 = (gg.fs.sc - b) / d;
            ans4 = (gg.sc.sc - b) / d;
        }
        if (ans1 < 0 && ans2 < 0) {
            cout << -1 << endd;
        }
        if (ans3 < 0 && ans4 < 0) {
            cout << -1 << endd;
        }
        if (ans2 < ans1) {
            swap(ans1, ans2);
        }
        if (ans4 < ans3) {
            swap(ans4, ans3);
        }
        tek.pb(mp(max(ans1, ans3), min(ans2, ans4)));
    }
    pr<double, double> kek;
    kek.sc = INF;
    kek.fs = 0;
    for (int i = 0; i < n; i++) {
        kek.fs = max(kek.fs, tek[i].fs);
        kek.sc = min(kek.sc, tek[i].sc);
    }
    if (kek.sc <= kek.fs) {
        cout << -1;
    } else {
        cout << setprecision(10);
        cout.fixed;
        cout << kek.fs;
    }
}