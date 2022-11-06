#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,c,q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        vector<pair<int,int>>arr(c+1);
        for(int i = 1; i<=c; i++){
            int l,r;
            cin >> l >> r;
            arr[i] = {l,r};
        }
        vector<int>len(c+1);
        len[0] = s.size();
        for(int i = 1; i<=c; i++){
            len[i] = len[i-1]+arr[i].second-arr[i].first+1;
        }
        while(q--){
            int k;
            cin >> k;
            for(int i = c; i>=1; i--){
                if(k<=len[i]&&k>len[i-1]){
                    int idx = k-len[i-1];
                    k = arr[i].first+idx-1;
                }
            }
            cout << s[k-1] << "\n";
        }
    }
    return 0;
}