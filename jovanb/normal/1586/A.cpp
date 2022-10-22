#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

bool prime(int x){
    if(x == 1) return 0;
    for(int i=2; i*i<=x; i++) if(x%i == 0) return 0;
    return 1;
}

int a[505];

void solve(){
    int n;
    cin >> n;
    int sum = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(!prime(sum)){
        cout << n << "\n";
        for(int i=1; i<=n; i++) cout << i << " ";
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; i++){
        if(!prime(sum - a[i])){
            cout << n-1 << "\n";
            for(int j=1; j<i; j++) cout << j << " ";
            for(int j=i+1; j<=n; j++) cout << j << " ";
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