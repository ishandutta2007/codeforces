#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, ans = 0;
    cin >> n;
    map<int, LL> mp;
    for(int i = 0, b; i < n; i += 1){
        cin >> b;
        mp[b - i] += b;
    }
    for(auto p : mp) ans = max(ans, p.second);
    cout << ans;
    return 0;
}