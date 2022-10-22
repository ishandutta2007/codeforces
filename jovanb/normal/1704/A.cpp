#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

bool ima[2];

void solve(){
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    ima[0] = ima[1] = 0;
    for(int i=m-1; i<n; i++){
        ima[a[i] - '0'] = 1;
    }
    for(int i=0; i<m-1; i++){
        if(a[i] != b[i]){
            cout << "NO\n";
            return;
        }
    }
    if(b.back() == '1'){
        if(ima[1]) cout << "YES\n";
        else cout << "NO\n";
    }
    else{
        if(ima[0]) cout << "YES\n";
        else cout << "NO\n";
    }
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