#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;

int a[N+5];
int b[N+5];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    int k;
    cin >> k;
    for(int i=1; i<=k; i++) cin >> b[i];
    vector <pair <ll, ll>> va, vb;
    for(int i=1; i<=n; i++){
        int cnt = 1;
        while(a[i]%m == 0){
            a[i] /= m;
            cnt *= m;
        }
        if(va.empty() || va.back().first != a[i]){
            va.push_back({a[i], cnt});
        }
        else va.back().second += cnt;
    }
    for(int i=1; i<=k; i++){
        int cnt = 1;
        while(b[i]%m == 0){
            b[i] /= m;
            cnt *= m;
        }
        if(vb.empty() || vb.back().first != b[i]){
            vb.push_back({b[i], cnt});
        }
        else vb.back().second += cnt;
    }
    if(va.size() != vb.size()){
        cout << "No\n";
        return;
    }
    for(int i=0; i<va.size(); i++){
        if(va[i] != vb[i]){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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