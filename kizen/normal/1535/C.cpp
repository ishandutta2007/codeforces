#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = (int)s.size();
        vector<vector<int>> sum(n, vector<int>(2));
        vector<vector<int>> sum2(n, vector<int>(2));
        for(int i = n - 1; i >= 0; --i){
            if(i % 2){
                if(s[i] == '0' || s[i] == '?') sum[i][0] = 1;
                if(s[i] == '1' || s[i] == '?') sum[i][1] = 1;
            }
            if(i < n - 1) sum[i][0] += sum[i + 1][0], sum[i][1] += sum[i + 1][1];
            if(i % 2 == 0){
                if(s[i] == '0' || s[i] == '?') sum2[i][0] = 1;
                if(s[i] == '1' || s[i] == '?') sum2[i][1] = 1;
            }
            if(i < n - 1) sum2[i][0] += sum2[i + 1][0], sum2[i][1] += sum2[i + 1][1];
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int l = 0, r = i, mid;
            if(i % 2 == 0) swap(sum, sum2);
            while(l < r){
                mid = (l + r) >> 1;
                if(sum[mid][0] - (i < n - 1 ? sum[i + 1][0] : 0) >= (i - mid + 1) / 2 + ((i - mid + 1) % 2) && 
                    sum2[mid][1] - (i < n - 1 ? sum2[i + 1][1] : 0) >= (i - mid + 1) / 2){
                    r = mid;
                }
                else if(sum[mid][1] - (i < n - 1 ? sum[i + 1][1] : 0) >= (i - mid + 1) / 2 + ((i - mid + 1) % 2) && 
                    sum2[mid][0] - (i < n - 1 ? sum2[i + 1][0] : 0) >= (i - mid + 1) / 2){
                    r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            if(i % 2 == 0) swap(sum, sum2);
            ans += (i - l + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}