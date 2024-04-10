#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1000000007;

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

int a[200005];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    for(int i=1; i<=n; i++){
        if((a[i] & a[1]) != a[1]){
            cout << "0\n";
            return;
        }
    }
    int res = 1;
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(a[i] == a[1]) cnt++;
    }
    res = mul(cnt, cnt-1);
    for(int i=n-2; i>=1; i--) res = mul(res, i);
    cout << res << "\n";
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