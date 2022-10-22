#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[105];
int b[105];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    sort(a+1, a+1+n);
    sort(b+1, b+1+n);
    bool g = 1;
    for(int i=1; i<=n; i++) g &= (a[i] == b[i] || a[i] + 1 == b[i]);
    if(g) cout << "YES\n";
    else cout << "NO\n";
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