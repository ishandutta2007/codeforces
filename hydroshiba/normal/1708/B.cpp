#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> ans;

    for(int i = 1; i <= n; ++i){
        if(i == 1){
            ans.push_back(l);
            continue;
        }

        if(l + (i - (l % i)) <= r) ans.push_back(l + (i - (l % i)));
        else if(l % i == 0) ans.push_back(l);
        else{
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for(int i : ans) cout << i << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}