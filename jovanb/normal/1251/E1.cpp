#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 200000;
vector <int> vec[MAXN+5];
multiset <int> vals;
int pre[MAXN+5];

void solve(){
    int n;
    cin >> n;
    for(int i=0; i<=n; i++){
        vec[i].clear();
        pre[i] = 0;
    }
    vals.clear();
    for(int i=1; i<=n; i++){
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
    }
    pre[0] = vec[0].size();
    for(int i=1; i<=n; i++){
        pre[i] = vec[i].size() + pre[i-1];
    }
    ll res = 0;
    int bought = 0;
    for(int i=n; i>=1; i--){
        for(auto c : vec[i]) vals.insert(c);
        while(pre[i-1] + bought < i){
            bought++;
            res += *vals.begin();
            vals.erase(vals.begin());
        }
    }
    cout << res << "\n";
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