#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

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
        int n, p;
        cin >> n >> p;
        vector<int> a(n);
        set<int> s;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s.insert(a[i]);
        }
        if (sz(s) == p) {
            cout << "0\n";
            continue;
        }
        int lst = p - 1;
        while (s.count(lst)) {
            --lst;
        }
        vector<pii> segs;
        int ans = 0;
        if (lst > a.back()) {
            ans = lst - a.back();
            segs.pb({a.back(), lst});
            bool fin = true;
            for (int x = a.back() - 1; x >= 0; --x) {
                if (!s.count(x)) {
                    fin = false;
                    break;
                }
            }
            if (fin) {
                cout << ans << "\n";
                continue;
            }
        }
        ans = (p - 1 - a.back());
        a.back() = p - 1;
        ++ans;
        a.back() = 0;
        bool total = true;
        for (int i = sz(a) - 2; i >= 0; --i) {
            if (a[i] == p - 1) {
                a[i] = 0;
            } else {
                ++a[i];
                total = false;
                break;
            }
        }
        if (total) {
            s.insert(1);
        }
        for (int i = 0; i < n; ++i) {
            s.insert(a[i]);
        }
        int ptr = p - 1;
        while (true) {
            if (s.count(ptr)) {
                --ptr;
                continue;
            }
            if (sz(segs) > 0 && ptr >= segs[0].first && ptr <= segs[0].second) {
                ptr = segs[0].first - 1;
                continue;
            }
            break;
        }
        if (ptr == -1) {
            cout << ans << "\n";
            continue;
        }
        cout << ans + ptr << "\n";
    }

}