#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,d;
        cin >> n >> d;
        multiset<int>s;
        vector<int>a(n+1);
        for(int i = 1; i<=n; i++){
            cin >> a[i];
        }
        for(int i = 1; i<=n; i++){
            s.insert(a[i]-a[i-1]-1);
        }
        int ans = *s.begin();
        for(int i = 1; i<=n; i++){
            if(i<n){
                s.erase(s.find(a[i+1]-a[i]-1));
                s.erase(s.find(a[i]-a[i-1]-1));
                s.insert(a[i+1]-a[i-1]-1);
                int v = *--s.end();
                ans = max(ans,min(*s.begin(),(v-1)/2));
                ans = max(ans,min(*s.begin(),d-a[n]-1));
                s.erase(s.find(a[i+1]-a[i-1]-1));
                s.insert(a[i+1]-a[i]-1);
                s.insert(a[i]-a[i-1]-1);
            }
            else{
                s.erase(s.find(a[i]-a[i-1]-1));
                int v = *--s.end();
                ans = max(ans,min(*s.begin(),(v-1)/2));
                ans = max(ans,min(*s.begin(),d-a[n-1]-1));

            }
        }
        cout << ans << "\n";
    }
    return 0;
}