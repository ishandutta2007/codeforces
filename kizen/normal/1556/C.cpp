#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1), pre(n + 2);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(i % 2) pre[i] = a[i] + pre[i - 1];
        else pre[i] = pre[i - 1] - a[i];
    }
    if(n % 2) pre[n + 1] = pre[n] - 1;
    else pre[n + 1] = pre[n] + 1;
    int ans = 0;
    for(int i = 0; i <= n; ++i){
        int low = pre[i + 1];
        for(int j = i + 1; j <= n; ++j){
            int l1 = min(pre[i], pre[i + 1] - 1), r1 = max(pre[i], pre[i + 1] - 1);
            int l2 = min(pre[j], pre[j + 1] - 1), r2 = max(pre[j], pre[j + 1] - 1);
            if(i % 2) l1 = min(pre[i], pre[i + 1] + 1), r1 = max(pre[i], pre[i + 1] + 1);
            if(j % 2) l2 = min(pre[j], pre[j + 1] + 1), r2 = max(pre[j], pre[j + 1] + 1);
            mi(r1, low), mi(r2, low);
            if(!(r1 < l2 || l1 > r2)){
                ans += min(r1, r2) - max(l1, l2) + 1;
            }
            mi(low, pre[j]), mi(low, pre[j + 1]);
        }

    }
    cout << ans;
    return 0;
}