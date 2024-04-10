#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> a(1000, 0);
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
           int x;
           cin >> x;
           a[x]++;
           ans = max(ans, a[x]);
    }
    cout << ans;
}