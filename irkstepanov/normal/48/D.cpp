#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    vector<int> ans(k, -1);
    map<int, vector<int> > mapa;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        mapa[x].pb(i);
    }
    int cc = 1;

    while (!mapa.empty()) {
        map<int, vector<int> >::iterator it = --mapa.end();
        int x = it->first;
        for (int j = 1; j <= x; ++j) {
            if (!mapa.count(j)) {
                cout << "-1\n";
                return 0;
            }
            it = mapa.lower_bound(j);
            int pos = it->second.back();
            ans[pos] = cc;
            it->second.pop_back();
            if (it->second.empty()) {
                mapa.erase(j);
            }
        }
        ++cc;
    }

    cout << cc - 1 << "\n";
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";



}