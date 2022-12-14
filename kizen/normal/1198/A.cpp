#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b;
    for(int i = 0; i < n; ++i){
        int j = i;
        while(j < n && a[i] == a[j]) ++j;
        b.push_back(j - i);
        i = j - 1;
    }
    int ans = (int)1e18;
    auto pre = b;
    for(int i = 1; i < (int)b.size(); ++i){
        pre[i] += pre[i - 1];
    }
    int md = 0;
    for(int i = n; i >= 0; --i){
        int lg = 0;
        while((1 << lg) < i) ++lg;
        if(lg * n <= 8 * k){
            md = i;
            break;
        }
    }
    for(int i = 0; i < (int)b.size(); ++i){
        int j = max(0ll, i - md + 1);
        int val = (pre[i] - (j ? pre[j - 1] : 0));
        mi(ans, n - val);
    }
    cout << ans << '\n';
    return 0;
}