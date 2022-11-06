#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int>arr(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        vector<int>psa(n+1);
        for(int i = 1; i<=n; i++){
            psa[i] = psa[i-1]+arr[i];
        }
        int ans = (int)1e18;
        int rq = psa[n]-k;
        //cout << rq << "\n";
        if(rq<=0){
            cout << "0\n";
            continue;
        }
        if(n==1){
            cout << rq << "\n";
            continue;
        }
        ans = rq;
        for(int i = 1; i<n; i++){
            int v = psa[n]-psa[i]; v-=arr[1]*(n-i);
            int rem = rq-v;
            int cnt = n-i;
            int d = n-i+1;
            if(rem<=0){
                ans = min(ans,cnt);
                continue;
            }
            cnt+=(rem+d-1)/(d);
            ans = min(ans,cnt);
        }
        cout << ans << "\n";
    }
    return 0;
}