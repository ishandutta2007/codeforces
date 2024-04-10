#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000;
LL a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, m, ans = 1;
    cin >> n >> m;
    for(int i = 0; i < n; i += 1) cin >> a[i];
    if(n > m) cout << 0;
    else{
        for(int i = 0; i < n; i += 1)
            for(int j = i + 1; j < n; j += 1)
                ans = ans * abs(a[i] - a[j]) % m;
        cout << ans;
    }
    return 0;
}