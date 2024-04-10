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
        ll n, x;
        cin >> n >> x;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);

        ll sm = 0;
        ll cnt = 0;
        for (int i = n-1; i >= 0; i--) {
            sm += a[i];
            cnt++;
            if (sm < cnt*x) {
                cnt--;
                break;
            }
        }
        cout << cnt << endl;
    }
}