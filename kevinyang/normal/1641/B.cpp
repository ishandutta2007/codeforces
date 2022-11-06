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
        if(true){
            set<int>s;
            for(int i = 1; i<=n; i++){
                if(s.find(arr[i])==s.end()){
                    s.insert(arr[i]);
                }
                else{
                    s.erase(arr[i]);
                }
            }
            if(s.size()>0){
                cout << "-1\n";
                continue;
            }
        }
        int add = 0;
        vector<int>a;
        for(int i = 1; i<=n; i++){
            a.push_back(arr[i]);
        }
        vector<pair<int,int>>ans;
        assert(n%2==0);
        int iter = n/2;
        vector<int>vals;
        for(int ite = 0; ite<iter; ite++){
            int idx = 0;
            for(int i = 1; i<a.size(); i++){
                if(a[i]==a[0]){
                    idx = i;
                    break;
                }
            }
            for(int j = 1; j<idx; j++){
                int ind = add+idx+j;
                ans.push_back({ind,a[j]});
            }
            add+=idx*2;
            vector<int>b;
            vals.push_back(idx*2);
            for(int i = idx-1; i>=1; i--){
                b.push_back(a[i]);
            }
            for(int i = idx+1; i<a.size(); i++){
                b.push_back(a[i]);
            }
            a.clear();
            for(int nxt: b){
                a.push_back(nxt);
            }
        }
        cout << ans.size() << "\n";
        for(pair<int,int>nxt: ans){
            cout << nxt.first << " " << nxt.second << "\n";
        }
        cout << vals.size() << "\n";
        for(int nxt: vals){
            cout << nxt << " ";
        }
        cout << "\n";
    }
    return 0;
}