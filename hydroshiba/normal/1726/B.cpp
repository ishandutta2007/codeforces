#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    if(m < n){
        cout << "NO\n";
        return;
    }
    if(n & 1){
        cout << "YES\n";
        for(int i = 0; i < n - 1; ++i) cout << "1 ";
        cout << m - (n - 1) << '\n';
    }
    else{
        if(m & 1) cout << "NO\n";
        else{
            cout << "YES\n";
            for(int i = 0; i < n - 2; ++i) cout << "1 ";
            cout << (m - (n - 2)) / 2 << ' ' << (m - (n - 2)) / 2 << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}