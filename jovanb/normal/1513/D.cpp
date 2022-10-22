#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[200005];
int conn[200005];

void solve(){
    int n, p;
    cin >> n >> p;
    ll left = n-1;
    vector <pair <int, int>> vec;
    for(int i=1; i<=n; i++){
        conn[i] = 0;
        cin >> a[i];
        vec.push_back({a[i], i});
    }
    ll res = 0;
    sort(vec.begin(), vec.end());
    for(auto c : vec){
        if(c.first >= p) break;
        if(conn[c.second]) continue;
        for(int i=c.second-1; i>=1; i--){
            if(a[i]%a[c.second]) break;
            conn[c.second] = 1;
            left--;
            res += c.first;
            if(conn[i]) break;
            conn[i] = 1;
        }
        for(int i=c.second+1; i<=n; i++){
            if(a[i]%a[c.second]) break;
            conn[c.second] = 1;
            left--;
            res += c.first;
            if(conn[i]) break;
            conn[i] = 1;
        }
    }
    cout << res + left*p << "\n";
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