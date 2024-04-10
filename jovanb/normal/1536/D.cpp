#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int b[200005];

void solve(){
    int n;
    cin >> n;
    set <int> q;
    for(int i=1; i<=n; i++) cin >> b[i];
    q.insert(-2e9);
    q.insert(2e9);
    for(int i=1; i<n; i++){
        auto p = q.lower_bound(b[i]);
        p--;
        auto d = q.upper_bound(b[i]);
        if(b[i+1] > *d || b[i+1] < *p){
            cout << "NO\n";
            return;
        }
        q.insert(b[i]);
    }
    cout << "YES\n";
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