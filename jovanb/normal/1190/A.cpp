#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll a[100005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    ll n, m, k;
    cin >> n >> m >> k;
    ll delt = 0;
    for(int i=1; i<=m; i++){
        cin >> a[i];
    }
    ll cnt = 0;
    while(delt < m){
        ll pg = (a[delt+1]-delt + k-1)/k;
        ll d = delt+1;
        while(d < m && (a[d+1]-delt + k-1)/k == pg) d++;
        cnt++;
        delt = d;
    }
    cout << cnt << "\n";
    return 0;
}