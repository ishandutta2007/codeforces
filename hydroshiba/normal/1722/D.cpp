#define x first
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n; cin >> n;

    string s;
    cin >> s;

    lol ans = 0;

    vector<ll> vec;

    for(int l = 0; l < n; ++l){
        ans += (s[l] == 'L' ? l : n - l - 1);

        if(s[l] == 'L' && l >= n - l - 1) continue;
        if(s[l] == 'R' && l <= n - l - 1) continue;

        vec.push_back(ll(max(l, n - l - 1), (s[l] == 'L' ? l : n - l - 1)));
    }

    sort(vec.begin(), vec.end(), greater<ll>());
    vec.resize(n);

    for(ll i : vec){
        ans -= i.second;
        ans += i.first;
        cout << ans << ' ';
    }

    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}