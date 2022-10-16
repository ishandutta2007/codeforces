#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll n, m;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    multiset<l_l> boy;
    vector<ll> girl(m);
    ll ans = 0;
    ll boymax = 0;
    for(int i = 0; i < n; i++) {
        l_l now;
        cin >> now.first;
        ans += now.first * m;
        boymax = max(boymax, now.first);
        now.second = m - 1;
        boy.insert(now);
    }
    boy.insert({1e9, 1e9});
    for(int i = 0; i < m; i++) cin >> girl[i];
    sort(girl.begin(), girl.end());
    if(boymax > girl[0]) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < m; i++) {
        auto itr = boy.upper_bound({girl[i], 1e9});
        itr--;
        ans += (girl[i] - (*itr).first);
        //cerr << girl[i] << " " << (*itr).first << " " << (*itr).second << endl;
        l_l now = *itr;
        boy.erase(itr);
        //cerr << now.first << " " << girl[i] << endl;
        if(now.first != girl[i]) now.second--;
        if(now.second > 0) boy.insert(now);
    }
    cout << ans << endl;
    return 0;
}