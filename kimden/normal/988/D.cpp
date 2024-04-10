#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll mod(ll x, ll y){
    ll o = x % y;
    o += y;
    o %= y;
    return o;
}

void update(vector<ll>& ans, pll x, ll k){
    if(ans.size() == 0 || ((ans[1] - ans[0]) / ans[2] < (x.second - x.first) / k)){
        ans = {x.first, x.second, k};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(all(a));
    vector<ll> ans = {};
    for(ll k = 1; k < 2000000001LL; k <<= 1LL){
        map<ll, pll> mp;
        for(int i = 0; i < n; ++i){
            ll val = mod(a[i], k);
            auto it = mp.find(val);
            if(it == mp.end()){
                mp[val] = {a[i], a[i]};
            }else if(it->second.second + k != a[i]){
                update(ans, it->second, k);
                mp[val] = {a[i], a[i]};
            }else{
                mp[val].second = a[i];
            }
        }
        for(auto& x: mp){
            update(ans, x.second, k);
        }
    }
    cout << min<ll>(3, (ans[1] - ans[0]) / ans[2] + 1) << endl;
    for(ll o = ans[0]; o <= ans[1] && o <= 2 * ans[2] + ans[0]; o += ans[2]){
        cout << o << " ";
    }
    cout << endl;

}