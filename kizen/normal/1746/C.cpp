#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        vector<pair<int, int>> srt;
        for(int i = 0; i < n; ++i){
            cin >> a[i];

            if(i){
                srt.push_back({a[i - 1] - a[i], i});
            }
        }
        sort(srt.begin(), srt.end());

        cout << "1 ";
        for(auto&i:srt){
            cout << i.second + 1 << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}