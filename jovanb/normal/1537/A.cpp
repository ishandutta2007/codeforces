#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 50;

int a[MAXN+5];

void solve(){
    int n;
    cin >> n;
    ll sum = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i]--;
        sum += a[i];
    }
    if(sum < 0) cout << "1\n";
    else if(sum == 0) cout << "0\n";
    else cout << sum << "\n";
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