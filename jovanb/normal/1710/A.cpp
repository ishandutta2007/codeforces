#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000000;

int a[N+5];

void solve(){
    ll n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    ll s1 = 0, s2 = 0;
    for(int i=1; i<=k; i++){
        cin >> a[i];
        ll h = a[i]/n;
        if(h > 1) s1 += h;
        h = a[i]/m;
        if(h > 1) s2 += h;
    }
    if(s1 >= m){
        for(int i=1; i<=k; i++){
            if(a[i]/n >= 3){
                cout << "Yes\n";
                return;
            }
        }
        if(m%2 == 0){
            cout << "Yes\n";
            return;
        }
    }
    if(s2 >= n){
        for(int i=1; i<=k; i++){
            if(a[i]/m >= 3){
                cout << "Yes\n";
                return;
            }
        }
        if(n%2 == 0){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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