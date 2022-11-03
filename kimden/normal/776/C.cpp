#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


int main() {
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> o;
    o.push_back(1);
    if(abs(k) != 1){
        ll cur = 1;
        while(abs(cur) < 1'000'000'000'000'000){
            cur *= k;
            o.push_back(cur);
        }
    }
    if(k == -1){
        o.push_back(-1);
    }
    vector<ll> a(n);
    map<ll, int> mp;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    mp[0] = 1;
    ll sum = 0;
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        sum += a[i];
        for(int j = 0; j < o.size(); ++j){
            if(mp.count(sum - o[j])){
                ans += mp[sum - o[j]];
            }
        }
        ++mp[sum];
    }
    cout << ans << endl;


}