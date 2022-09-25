#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<LL> d(n);
        for (LL& _ : d) cin >> _;
        sort(d.begin(), d.end());
        LL ans = d.back(), sum = 0;
        for (int i = 1; i < n; i += 1) {
            ans -= d[i] * i - sum;
            sum += d[i];
        }
        cout << ans << "\n";
    }
    return 0;
}