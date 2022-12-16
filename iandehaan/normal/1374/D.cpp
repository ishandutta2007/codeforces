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
        ll n, k;
        cin >> n >> k;
        map<ll, ll> rems;
        ll out = -1;
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            ll rem = x%k;
            if (rem != 0) rem = k-rem;
            if (rems.find(rem) == rems.end()) rems[rem] = 0;
            rems[rem]++;
            if (rem != 0) out = max(out, rem+k*(rems[rem]-1));
        }
        cout << out+1 << '\n';
    }
}