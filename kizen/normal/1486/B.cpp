#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
        long long n; cin >> n;
        vector<long long> x(n), y(n);
        for(long long i = 0; i < n; ++i){
            cin >> x[i] >> y[i];
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        long long ans = 1;
        if(n % 2 == 0 && x[n / 2] > x[n / 2 - 1]){
            ans *= (x[n / 2] - x[n / 2 - 1] + 1);
        }
        if(n % 2 == 0 && y[n / 2] > y[n / 2 - 1]){
            ans *= (y[n / 2] - y[n / 2 - 1] + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}