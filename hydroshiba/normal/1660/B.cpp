#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    if(n < 2){
        if(arr[n - 1] == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    else if(arr[n - 1] - arr[n - 2] < 2) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}