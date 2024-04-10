#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[105], b[105];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int j=1; j<=n; j++) cin >> b[j];
    int m1 = 0, m2 = 0;
    for(int i=1; i<=n; i++){
        m1 = max(m1, min(a[i], b[i]));
        m2 = max(m2, max(a[i], b[i]));
    }
    cout << m1*m2 << "\n";
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