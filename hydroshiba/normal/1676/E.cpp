#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<lol> vec(n);
    for(lol &i : vec) cin >> i;

    sort(vec.begin(), vec.end(), greater<int>());
    vector<lol> pre(n + 1);

    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i - 1] + vec[i - 1];
    }

    while(q--){
        lol x;
        cin >> x;

        int pos = lower_bound(pre.begin(), pre.end(), x) - pre.begin();

        if(pos > n) cout << "-1\n";
        else cout << pos << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}