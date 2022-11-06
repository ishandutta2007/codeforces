#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int>a(m+1);
        vector<int>cnt(n+1);
        for(int i = 1; i<=m; i++){
            cin >> a[i];
            cnt[a[i]]++;
        }
        int low = 0; int high = (int)1e9; int mid = (low+high)/2;
        while(low+1<high){
            int total = 0;
            for(int i = 1; i<=n; i++){
                int mn = min(mid,cnt[i]);
                int v = mid-mn;
                total+=mn;
                total+=v/2;
            }
            if(total>=m)high = mid;
            else low = mid;
            mid = (low+high)/2;
        }
        cout << high << "\n";
    }
    return 0;
}