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
        vector<int>arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        set<int>s;
        set<int>s2;
        for(int i = 0; i<n; i+=2){
            s.insert(arr[i]%2);
        }
        for(int i = 1; i<n; i+=2){
            s2.insert(arr[i]%2);
        }
        if(s.size()+s2.size()==2){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}