#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll d[1000005];
ll a[1000005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> d[i];
    }
    for(int i=1; i<=n; i++){
        if(i <= (n+1)/2) a[i] = d[2*i-1];
        else a[i] = d[2*(i-(n+1)/2)];
        a[n+i] = a[i];
    }
    ll sum = 0;
    ll res = 0;
    for(int i=1; i<=(n+1)/2; i++) sum += a[i];
    res = max(res, sum);
    for(int i=(n+1)/2+1; i<=2*n; i++){
        sum += a[i];
        sum -= a[i-(n+1)/2];
        res = max(res, sum);
    }
    cout << res;
    return 0;
}