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
        vector<int>freq(n+1);
        vector<int>psa(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
            freq[arr[i]]++;
        }
        for(int i = 1; i<=n; i++){
            psa[i] = psa[i-1]+freq[i];
        }
        int low = -1; int high = n+1; int mid = (low+high)/2;
        while(low+1<high){
            bool f = false;
            for(int i = mid; i<=n; i++){
                int bad = n-(psa[i]-psa[i-mid]);
                if(n-bad*2>=k){
                    f = true;
                }
            }
            if(f)high = mid;
            else low = mid;
            mid = (low+high)/2;
        }
        int l = 0; int r = 0;
        for(int i = high; i<=n; i++){
            int bad = n-(psa[i]-psa[i-high]);
            if(n-bad*2>=k){
                l = i-high+1; r = i;
                break;
            }
        }
        assert(l>0&&r>0);
        int cnt = 1;
        int cur = 0;
        cout << l << " " << r << "\n";
        int prev = 1;
        for(int i = 1; i<=n; i++){
            if(l<=arr[i]&&arr[i]<=r){
                cur++;
            }
            else{
                cur--;
            }
            if(cur==1&&cnt!=k){
                cout << prev << " " << i << "\n";
                prev = i+1;
                cur = 0;
                cnt++;
            }
        }
        //cout << cnt << "\n";
        cout << prev << " " << n << "\n";//
    }
    return 0;
}