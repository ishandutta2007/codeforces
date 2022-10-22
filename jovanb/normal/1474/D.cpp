#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll pre[300005];
ll suf[300005];
ll a[300005];

bool moze(vector <ll> v){
    for(int i=1; i<v.size(); i++){
        v[i] -= v[i-1];
        if(v[i] < 0) return 0;
    }
    return v.back() == 0;
}

bool solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        pre[i] = a[i];
        if(pre[i-1] < 0) pre[i] = -1;
        else pre[i] -= pre[i-1];
        if(pre[i] < 0) pre[i] = -1;
    }
    if(pre[n] == 0) return 1;
    suf[n+1] = 0;
    for(int i=n; i>=1; i--){
        suf[i] = a[i];
        if(suf[i+1] < 0) suf[i] = -1;
        else suf[i] -= suf[i+1];
        if(suf[i] < 0) suf[i] = -1;
    }
    for(int i=1; i<n; i++){
        if(pre[i-1] >= 0 && suf[i+2] >= 0){
            if(moze({pre[i-1], a[i+1], a[i], suf[i+2]})) return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}