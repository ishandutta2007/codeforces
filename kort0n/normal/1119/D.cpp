#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll n;
ll sum[100050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    vector<ll> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    n = s.size();
    vector<ll> delta(n);
    for(int i = 1; i < n; i++) {
        delta[i] = s[i] - s[i - 1];
    }
    delta[0] = -1;
    sort(delta.begin(), delta.end());
    for(int i = 1; i < n; i++) {
        //cerr << i << " " << delta[i] << endl;
        sum[i] = sum[i - 1] + delta[i];
    }
    ll q;
    cin >> q;
    while(q--) {
        ll l, r;
        cin >> l >> r;
        ll val = r - l;
        ll num = distance(delta.begin(), upper_bound(delta.begin(), delta.end(), val)) - 1;
        cout << sum[num] + (n - num) * (val + 1);
        if(q > 0) cout << " ";
    }
    cout << endl;
    return 0;
}