#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n), cnt(n + 1);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            ++cnt[a[i]];
        }
        for(int i = 1; i <= n; ++i){
            cnt[i] += cnt[i - 1];
        }
        int ans = (int)1e9, j = 0, pos = -1;
        for(int i = 1; i <= n; ++i){
            while(j <= n && cnt[j] - cnt[i - 1] < (n - (cnt[j] - cnt[i - 1])) + k) ++j;
            if(j <= n){
                if(j - i < ans){
                    ans = j - i;
                    pos = i;
                }
            }
        }
        cout << pos << ' ' << pos + ans << '\n';
        int now = -1;
        for(int i = 1; i < k; ++i){
            int pre = now, val = 0;
            while(true){
                ++now; val += (pos <= a[now] && a[now] <= pos + ans ? 1 : -1);
                if(val > 0){
                    break;
                }
            }
            cout << pre + 1 + 1 << ' ' << now + 1 << '\n';
        }
        cout << now + 1 + 1 << ' ' << n << '\n';
    }
    return 0;
}