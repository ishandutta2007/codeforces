#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n;
    cin >> n;
    int x = 1;
    int cnt = 0;
    while(x <= n){
        n -= x;
        cnt++;
        x += 2;
    }
    cnt += (n > 0);
    cout << cnt << "\n";
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