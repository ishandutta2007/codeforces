#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    int ans = 0;
    int mn = 9999941;
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> p[i];
        mn = min(mn, p[i]);
        ans += a[i] * mn;
    }
    cout << ans << endl;
}