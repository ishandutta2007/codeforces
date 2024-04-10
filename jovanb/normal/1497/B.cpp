#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int cnt[100005];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) cnt[i] = 0;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        cnt[x%m]++;
    }
    int res = 0;
    for(int i=1; i<m-i; i++){
        if(cnt[i] == cnt[m-i] && cnt[i]) res++;
        else res += cnt[i] + cnt[m-i] - 2*min(cnt[i], cnt[m-i]);
    }
    res += (cnt[0] > 0);
    if(m%2 == 0) res += (cnt[m/2] > 0);
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}