#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n, m;
    cin >> n >> m;
    if(n == 1){
        cout << "Yes\n";
        cout << m << "\n";
        return;
    }
    m -= n - 1;
    if(m <= 0){
        cout << "No\n";
        return;
    }
    if(m == 1){
        cout << "Yes\n";
        for(int i=1; i<=n; i++) cout << 1 << " ";
        cout << "\n";
        return;
    }
    if(n%2){
        cout << "Yes\n";
        for(int i=1; i<n; i++) cout << 1 << " ";
        cout << m << "\n";
        return;
    }
    if(m%2 == 0){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    int nv = (m + 1)/2;
    for(int i=1; i<n-1; i++) cout << 1 << " ";
    cout << nv << " " << nv << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}