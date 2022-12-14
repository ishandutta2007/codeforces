#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i]; --a[i];
        }
        vector<int> cnt(n);
        for(int i = 0; i < n; ++i){
            int pos = i - a[i];
            if(pos < 0) pos += n;
            ++cnt[pos];
        }
        vector<int> use;
        if(n <= 3){
            for(int i = 0; i < n; ++i) use.push_back(i);
        }
        else{
            for(int i = 0; i < n; ++i){
                if(cnt[i] >= n - m * 2){
                    use.push_back(i);
                }
            }
        }
        vector<int> ans;
        for(auto&k:use){
            int nval = 0;
            vector<int> b = a;
            for(int i = 0; i < n; ++i){
                while(true){
                    int pos = (b[i] + k) % n;
                    if(pos == i){
                        break;
                    }
                    ++nval;
                    swap(b[i], b[pos]);
                }
            }
            if(nval <= m){
                ans.push_back(k);
            }
        }
        cout << (int)ans.size() << ' ';
        for(auto&i:ans) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}