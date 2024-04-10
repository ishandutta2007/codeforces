#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    ll suma = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        suma += a[i];
    }
    sort(all(a));
    reverse(all(a));

    if (suma < m) {
        cout << "-1\n";
        return 0;
    }

    suma = 0;
    int ans = n;
    for (int i = 0; i < n; ++i) {
        suma += a[i];
        if (suma < m) {
            continue;
        }
        int z = i + 1;
        int lf = 0, rg = z;
        while (rg - lf > 1) {
            int k = (lf + rg) >> 1;
            ll sum = suma;
            ll s = (z - k) / k;
            sum -= k * s * (s + 1) / 2;
            ll rem = z - k - k * s;
            sum -= rem * (s + 1);
            if (sum >= m) {
                rg = k;
            } else {
                lf = k;
            }
        }
        ans = min(ans, rg);
    }

    

    cout << ans << "\n";
    
}