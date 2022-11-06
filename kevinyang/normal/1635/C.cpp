#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,pair<int,int>>
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>arr(n+5);
        vector<pair<int,int>>suf(n+5);
        suf[n+1] = {-(int)2e9,n+1};
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        for(int i = n; i>=1; i--){
            pair<int,int>p = {arr[i],i};
            suf[i] = max(suf[i+1],p);
        }
        set<pii>s;
        for(int i = 1; i<=n; i++){
            pii p = {arr[i]-suf[i+1].first,{i,suf[i+1].second}};
            s.insert(p);
        }
        arr[0] = -(int)2e9;
        vector<int>x;
        vector<int>y;
        vector<int>z;
        for(int i = 1; i+1<n; i++){
            pii p = {arr[i]-suf[i+1].first,{i,suf[i+1].second}};
            s.erase(p);
            auto v = *s.begin();
            int val = v.first;
            if(arr[i]<arr[i-1]){
                arr[i] = val;
                x.push_back(i);
                y.push_back(v.second.first);
                z.push_back(v.second.second);
            }
            else if(arr[i]>val){
                x.push_back(i);
                y.push_back(v.second.first);
                 z.push_back(v.second.second);
                arr[i] = min(val,arr[i]);
            }
            
        }
        bool f = true;
        for(int i = 2; i<=n; i++){
            if(arr[i]<arr[i-1]){
                f = false;
            }
        }
        if(!f){
            cout << "-1\n";
            continue;
        }
        else{
            cout << x.size() << "\n";
            for(int i = 0; i<x.size(); i++){
                cout << x[i] << " " << y[i] << " " << z[i] << "\n";
            }
        }
    }
    return 0;
}