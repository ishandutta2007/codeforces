//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 2E5+7;
const ll INF = 1E9;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> V1, V2;
        for (ll i = 1; i <= n * 2; ++i) {
            ll x, y;
            cin >> x >> y;
            if (x == 0)
                V1.push_back(abs(y));
            else V2.push_back(abs(x));
        }
        sort(V1.begin(), V1.end());
        sort(V2.begin(), V2.end());
        ld res = 0;
        for (ll i = 0; i < n; ++i) {
            res += sqrt(V1[i] * V1[i] + V2[i] * V2[i]);
        }
        cout << fixed << setprecision(10) << res << endl;
    }
    return 0;
}