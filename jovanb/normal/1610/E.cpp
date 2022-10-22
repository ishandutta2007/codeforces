#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

ll a[N+5];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    int res = 0;
    for(int i=1; i<=n;){
        int j = i;
        int cnt = 1;
        while(j < n && a[j+1] == a[i]) j++, cnt++;
        if(j == n){
            res = max(res, cnt);
            break;
        }
        int k = j + 1;
        cnt++;
        while(k <= n){
            int g = lower_bound(a+1, a+1+n, 2*a[k] - a[i]) - a;
            g = max(g, k + 1);
            if(g > n) break;
            cnt++;
            k = g;
        }
        res = max(res, cnt);
        i = j + 1;
    }
    cout << n - res << "\n";
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