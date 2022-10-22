#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5000;

ll a[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    ll res = 100000000000000000LL;
    for(int i=1; i<=n; i++){
        ll sum = 0;
        ll lst = 0;
        for(int j=i-1; j>=1; j--){
            ll k = (lst + a[j])/a[j];
            lst = k*a[j];
            sum += k;
        }
        lst = 0;
        for(int j=i+1; j<=n; j++){
            ll k = (lst + a[j])/a[j];
            lst = k*a[j];
            sum += k;
        }
        res = min(res, sum);
    }
    cout << res << "\n";
    return 0;
}