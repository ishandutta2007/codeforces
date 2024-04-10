#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll out = 0;
        for (int i = 0; i < 7; i++) {
            vector<int> a;
            vector<int> b;
            for (int j = 1; j <= n; j++) {
                if (j & (1 << i)) {
                    a.pb(j);
                } else {
                    b.pb(j);
                }
            }
            if (a.empty() || b.empty()) break;
            cout << a.size() << ' ' << b.size() << ' ';
            for (int c : a) cout << c << ' ';
            for (int c : b) cout << c << ' ';
            cout << endl;
            ll resp;
            cin >> resp;
            out = max(out, resp);
        }
        cout << -1 << ' ' << out << endl;
    }
}