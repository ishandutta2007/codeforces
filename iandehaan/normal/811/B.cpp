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
 
 
    ll n, m;
    cin >> n >> m;
    ll p[n];
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < m; i++) {
        ll l, r, x;
        cin >> l >> r >> x;
        if (x < l || x > r) {
            cout << "Yes" << endl;
            continue;
        }

        ll mid = p[x-1];
        ll cnt = 0;

        for (int i = l-1; i <= r-1; i++) {
            if (p[i] < p[x-1]) cnt++;
        }

        if (l + cnt == x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}