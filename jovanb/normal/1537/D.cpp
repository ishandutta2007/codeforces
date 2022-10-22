#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int pwr(int x){
    int g = 0;
    while(x%2 == 0 && x > 2){
        x /= 2;
        g++;
    }
    if(x > 2) g = 1;
    return g;
}

void solve(){
    int n;
    cin >> n;
    if(n%2){
        cout << "Bob\n";
        return;
    }
    int x = pwr(n);
    if(x%2) cout << "Alice\n";
    else cout << "Bob\n";
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