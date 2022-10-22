#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct offer{
    ll a, b, k;
} a[505];

bool cmp(offer a, offer b){
    return a.b > b.b;
}

ll dp[505];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i].a >> a[i].b >> a[i].k;
    }
    sort(a+1, a+1+n, cmp);
    for(int i=1; i<=n; i++){
        for(int j=n; j>=0; j--){
            dp[j+1] = max(dp[j+1], dp[j] + a[i].a-j*a[i].b);
            dp[j] += max(0LL, a[i].a - a[i].b*a[i].k);
        }
    }
    ll res = 0;
    for(int i=0; i<=n; i++) res = max(res, dp[i]);
    cout << res << "\n";
    return 0;
}