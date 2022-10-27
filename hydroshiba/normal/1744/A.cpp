#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr) cin >> i;

    string s; cin >> s;
    map<int, char> cow;

    for(int i = 0; i < n; ++i){
        if(cow.count(arr[i]) == 0) cow[arr[i]] = s[i];
        else if(cow[arr[i]] != s[i]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();
}