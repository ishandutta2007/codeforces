#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<bool>prime((int)1e6+5,true);
int f(vector<int>arr,int n){
    vector<int>psa(n+1);
    set<int>s;
    for(int i = 1; i<=n; i++){
        if(arr[i]==1)continue;
        if(prime[arr[i]]){
            psa[i]++;
        }
        else{
            psa[i]+=2;
        }
        s.insert(i);
        psa[i]+=psa[i-1];
    }
    s.insert(0);
    s.insert(n+1);
    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(prime[arr[i]]){
            int l = *--s.lower_bound(i); l++;
            int r = *s.upper_bound(i); r--;
            ans+=(i-l+1)*(r-i+1)-1;
        }
    }
    return ans;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int mxn = (int)1e6;
    prime[0] = prime[1] = false;
    for(int i = 2; i<=mxn; i++){
        for(int j = 2*i; j<=mxn; j+=i){
            prime[j] = false;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int>arr(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        int ans = 0;
        for(int j = 1; j<=k; j++){
            vector<int>a;
            a.push_back(0);
            for(int i = j; i<=n; i+=k){
                a.push_back(arr[i]);
            }
            ans+=f(a,a.size()-1);
        }
        cout << ans << "\n";
    }
    return 0;
}