#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        ll ans = v[0] * v.back();
        vector<ll> divisor;
        for(ll i = 2; i * i <= ans; i++) {
            if(ans % i != 0) continue;
            divisor.push_back(i);
            if(i * i != ans) divisor.push_back(ans / i);
        }
        sort(divisor.begin(), divisor.end());
        bool ok = true;
        if(divisor.size() != v.size()) ok = false;
        for(int i = 0; i < divisor.size(); i++) {
            if(ok && v[i] != divisor[i]) ok = false;
        }
        if(ok) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}