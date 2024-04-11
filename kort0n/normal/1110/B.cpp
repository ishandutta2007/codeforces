#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    ll n, m, k;
    cin >> n >> m >> k;
    ll b[100050];
    vector<ll> delta(n - 1);
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for(int i = 1; i < n; i++) {
        delta[i - 1] = b[i + 1] - b[i] - 1;
    }
    sort(delta.begin(), delta.end());
    ll ans = n;
    for(int i = 0; i + k < n; i++) {
        //cout << i << " " << delta[i] << endl;
        ans += delta[i];
    }
    cout << ans << endl;
    return 0;
}