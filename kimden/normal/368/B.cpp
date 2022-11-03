#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a[100002], dp[100002];
map<int, bool> mp;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, l;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    dp[n] = 0;
    for(int i = n - 1; i >= 0; --i){
        if(!mp[a[i]]){
            dp[i] = dp[i + 1] + 1;
            mp[a[i]] = true;
        } else {
            dp[i] = dp[i + 1];
        }
    }
    for(int i = 0; i < m; ++i){
        cin >> l;
        cout << dp[l - 1] << endl;
    }
    return 0;
}