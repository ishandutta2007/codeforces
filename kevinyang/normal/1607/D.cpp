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
        vector<int>arr(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        string s;
        cin >> s;
        vector<int>low;
        vector<int>high;
        for(int i = 1; i<=n; i++){
            if(s[i-1]=='B')low.push_back(arr[i]);
            else high.push_back(arr[i]);
        }
        sort(low.begin(),low.end());
        sort(high.begin(),high.end());
        bool f = true;
        int v = count(s.begin(),s.end(),'B');
        for(int i = 1; i<=v; i++){
            if(low[i-1]<i)f = false;
        }
        for(int i = v+1; i<=n; i++){
            if(high[i-v-1]>i)f = false;
        }
        if(f)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}