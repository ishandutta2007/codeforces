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

    if(n % 2 == 0){
        cout << "YES\n";
        return;
    }

    for(int i = 1; i < n; ++i){
        if(arr[i] <= arr[i - 1]){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}