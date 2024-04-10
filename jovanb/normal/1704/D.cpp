#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <pair <ll, int>> vec;
    for(int i=1; i<=n; i++){
        ll p = 0;
        ll sum = 0;
        for(int j=1; j<=m; j++){
            ll x;
            cin >> x;
            p += x;
            sum += p;
        }
        vec.push_back({sum, i});
    }
    sort(vec.begin(), vec.end());
    if(vec[0].first != vec[1].first){
        cout << vec[0].second << " " << abs(vec[0].first - vec[1].first) << "\n";
    }
    else{
        cout << vec.back().second << " " << abs(vec[0].first - vec.back().first) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}