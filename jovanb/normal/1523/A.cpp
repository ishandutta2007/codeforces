#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[10005];
int b[10005];

void solve(){
    int n, m;
    cin >> n >> m;
    m = min(m, n);
    string s;
    cin >> s;
    for(int i=1; i<=n; i++) a[i] = s[i-1] - '0';
    a[n+1] = 0;
    while(m--){
        for(int i=1; i<=n; i++){
            b[i] = 0;
            if(a[i-1]+a[i+1] == 1) b[i] = 1;
        }
        for(int i=1; i<=n; i++) a[i] |= b[i];
    }
    for(int i=1; i<=n; i++) cout << a[i];
    cout << "\n";
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