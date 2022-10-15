#include "bits/stdc++.h"
using namespace std;

int cost(string &a, string &b){
    int sum = 0;

    for(int i = 0; i < a.size(); ++i){
        int val = abs((a[i] - 'a') - (b[i] - 'a'));
        //val = min(val, 26 - val);
        sum += val;
    }

    return sum;
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    for(string &s : arr) cin >> s;

    int ans = INT_MAX;

    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j){
            ans = min(ans, cost(arr[i], arr[j]));
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