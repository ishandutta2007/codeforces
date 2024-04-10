#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 200000;

int a[MAXN+5];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    int mn = a[2] - a[1];
    for(int i=2; i<=n; i++) mn = min(mn, a[i] - a[i-1]);
    for(int i=2; i<=n; i++){
        if(a[i] - a[i-1] == mn){
            cout << a[i-1] << " ";
            for(int j=i+1; j<=n; j++) cout << a[j] << " ";
            for(int j=1; j<i-1; j++) cout << a[j] << " ";
            cout << a[i] << " ";
            cout << "\n";
            return;
        }
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