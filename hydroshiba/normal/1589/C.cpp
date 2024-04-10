#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0; i < n; ++i){
        if(a[i] == b[i]) continue;
        if(a[i] + 1 != b[i]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}