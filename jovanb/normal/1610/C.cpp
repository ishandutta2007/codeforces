#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

int a[N+5], b[N+5];

bool check(int n, int k){
    int taken = 0;
    for(int i=1; i<=n; i++) if(taken <= a[i] && k - taken - 1 <= b[i]) taken++;
    return taken >= k;
}

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> b[i] >> a[i];
    int l = 1, r = n, res = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(n, mid)){
            l = mid + 1;
            res = mid;
        }
        else r = mid - 1;
    }
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