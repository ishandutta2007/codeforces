#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll a[35];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    ll L;
    cin >> n >> L;
    ll tr = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    n = 30;
    for(int i=1; i<=n; i++){
        if(a[i]) a[i] = min(a[i], 2*a[i-1]);
        else a[i] = 2*a[i-1];
    }
    ll res = a[30];
    for(int j=30; j>=0; j--){
        if((1<<j) & L) tr += a[j];
        else res = min(res, tr + a[j]);
    }
    cout << min(res, tr) << "\n";
    return 0;
}