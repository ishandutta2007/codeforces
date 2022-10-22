#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[505];
int gde[505];

void prnt(int n){
    for(int i=1; i<=n; i++) cout << a[i] << " ";
    cout << "\n";
}

void solve(){
    int n;
    cin >> n;
    int posl = -1;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        gde[a[i]] = i;
        if(a[i] != i && posl == -1) posl = i - 1;
    }
    if(posl == -1){
        prnt(n);
        return;
    }
    reverse(a+posl+1, a+gde[posl+1]+1);
    prnt(n);
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