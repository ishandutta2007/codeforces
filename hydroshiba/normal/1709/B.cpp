#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    lol n, m;
    cin >> n >> m;

    vector<lol> arr(n);
    for(lol &i : arr) cin >> i;

    vector<lol> p, pr;
    for(lol i = 1; i < n; ++i){
        p.push_back(max(arr[i - 1] - arr[i], 0LL));
        pr.push_back(max(arr[i] - arr[i - 1], 0LL));

        if(i != 1){
            p[i - 1] += p[i - 2];
            pr[i - 1] += pr[i - 2];
        }
    }

    p.insert(p.begin(), 0);
    pr.insert(pr.begin(), 0);

    while(m--){
        lol l, r;
        cin >> l >> r;

        --l, --r;
        if(l < r) cout << p[r] - p[l] << '\n';
        else cout << pr[l] - pr[r] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    while(t--)
        solve();
}