#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll a[5005];

ll solve(int l, int r, ll odz){
    if(r < l) return 0;
    if(l == r){
        if(a[l] == odz) return 0;
        return 1;
    }
    int tr = l;
    for(int i=l; i<=r; i++){
        if(a[i] < a[tr]) tr = i;
    }
    return min(r-l+1LL, solve(l, tr-1, a[tr]) + solve(tr+1, r, a[tr]) + a[tr] - odz);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cout << solve(1, n, 0);
    return 0;
}