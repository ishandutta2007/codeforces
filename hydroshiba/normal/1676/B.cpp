#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr) cin >> i;

    int ans = INT_MAX;

    for(int i = 0; i < n; ++i){
        int sum = 0;
        for(int j = 0; j < n; ++j){

            if(arr[j] < arr[i]){
                sum = INT_MAX;
                break;
            }
            sum += abs(arr[i] - arr[j]);
        }

        ans = min(ans, sum);
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