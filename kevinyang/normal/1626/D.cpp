#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>freq(n+1);
        for(int i = 1; i<=n; i++){
            int x;
            cin >> x;
            freq[x]++;
        }
        vector<int>psa(n+1);
        for(int i = 1; i<=n; i++){
            psa[i] = psa[i-1]+freq[i];
        }
        vector<int>p2;
        for(int i = 0; i<20; i++){
            p2.push_back(1<<i);
        }
        int ans = *lower_bound(p2.begin(),p2.end(),psa[n])-psa[n]+2;
        for(int i = 1; i<=n-1; i++){
            vector<int>cand;
            for(int p: p2){
                int low = i-1; int high = n+1; int mid = (low+high)/2;
                while(low+1<high){
                    if(psa[mid]-psa[i]<=p){
                        low = mid;
                    }
                    else{
                        high = mid;
                    }
                    mid = (low+high)/2;
                }
                cand.push_back(low);
            }
            for(int p: p2){
                int low = i-1; int high = n+1; int mid = (low+high)/2;
                while(low+1<high){
                    if(psa[n]-psa[mid]<=p){
                        high = mid;
                    }
                    else{
                        low = mid;
                    }
                    mid = (low+high)/2;
                }
                cand.push_back(high);
            }
            for(int nxt: cand){
                int v = *lower_bound(p2.begin(),p2.end(),psa[i])-psa[i];
                v+=*lower_bound(p2.begin(),p2.end(),psa[nxt]-psa[i])-(psa[nxt]-psa[i]);
                v+=*lower_bound(p2.begin(),p2.end(),psa[n]-psa[nxt])-(psa[n]-psa[nxt]);
                ans = min(ans,v);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}