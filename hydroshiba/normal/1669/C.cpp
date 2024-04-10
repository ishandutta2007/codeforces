#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int &i : a) cin >> i;
    
    for(int i = 0; i < n - 2; ++i) if(a[i] % 2 != a[i + 2] % 2){
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}