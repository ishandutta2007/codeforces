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
        ll lastp, lastc;
        cin >> lastp >> lastc;
        bool good = true;
        if (lastp < lastc) good = false;
        
        for (int i = 1; i < n; i++) {
            ll p, c;
            cin >> p >> c;
            if (p < lastc || c < lastc) good = false;
            if ((c-lastc) > (p-lastp)) good = false;
            lastp = p;
            lastc = c;
        }
        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}