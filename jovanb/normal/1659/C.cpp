#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 200000;

ll x[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        ll a, b;
        cin >> n >> a >> b;
        for(int i=1; i<=n; i++) cin >> x[i];
        ll res = x[n]*x[n];
        ll sum = x[n];
        for(int i=n-1; i>=0; i--){
            res = min(res, a*x[i] + b*x[i] + b*(sum - (n-i)*x[i]));
            sum += x[i];
        }
        cout << res << "\n";
    }
    return 0;
}