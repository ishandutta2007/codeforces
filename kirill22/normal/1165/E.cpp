#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int MOD = 998244353;
    int n, ans = 0 ;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0;i <n;i++){
        cin >> a[i];
    }
    for(int i = 0;i  <n;i++){
        cin >> b[i];
    }
    for(int i = 0;i < n;i++){
            a[i] = (a[i] * (i + 1) * (n - i));
    }
    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());
    for(int i = 0;i < n;i++){
        ans = (ans + (a[i] % MOD) * (b[i] % MOD)) % MOD;
    }


    cout << (ans) % MOD;
}