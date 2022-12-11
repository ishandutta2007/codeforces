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

    int n, k;
    cin >> n >> k;

    map<int, int> mapa;
    int p = 0;
    int m = (1 << k) - 1;
    ++mapa[p];
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        p ^= x;
        ++mapa[p];
        mapa[m ^ p];
    }

    
    ll ans = 0;
    for (auto it : mapa) {
        //cout << it.first << " " << it.second << endl;
        int a = it.first;
        int b = (a ^ m);
        if (a > b) {
            continue;
        }
        int x = it.second;
        int y = 0;
        if (mapa.count(b)) {
            y = mapa[b];
        }
        ans += ll(n + 1 - x - y) * (x + y);
        ans += ll((x + y + 1) / 2) * ((x + y) / 2) * 2;
        //cout << "!" << ans << endl;
    }
    //cout << ans << "\n";
    cout << ans / 2 << "\n";
    
}