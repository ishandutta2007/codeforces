#include <bits/stdc++.h>
#define int long long
using namespace std;

int cnt[(int)1e5 + 4][2];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());
        for(int i = 0; i < n; ++i){
            ++cnt[a[i]][i % 2];
            --cnt[b[i]][i % 2];
        }
        int can = 1;
        for(auto&i:a){
            if(cnt[i][0] || cnt[i][1]){
                can = 0;
                break;
            }
        }
        for(int i = 0; i < n; ++i){
            --cnt[a[i]][i % 2];
            ++cnt[b[i]][i % 2];
        }
        if(can) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}