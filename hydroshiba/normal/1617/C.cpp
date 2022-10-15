#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n;
    cin >> n;

    vector<int> arr;
    vector<bool> taken(n + 1);

    for(int i = 0; i < n; ++i){
        int val;
        cin >> val;

        if(val <= n && !taken[val]){
            taken[val] = 1;
            continue;
        }

        arr.push_back(val);
    }

    sort(arr.begin(), arr.end());

    vector<int> vec;
    for(int i = 1; i <= n; ++i) if(!taken[i]) vec.push_back(i);

    int ans = 0;

    for(int i = 0; i < arr.size(); ++i){
        if(arr[i] == vec[i]) continue;

        int val = arr[i] - vec[i];
        if(val <= vec[i]){
            cout << "-1\n";
            return;
        }

        ++ans;
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}