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
        vector<string>arr(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        bool f = false;
        if(true){
            map<string,int>hm;
            vector<int>mx(1000);
                for(int i = 1; i<=n; i++){
                string s = arr[i];
                reverse(s.begin(),s.end());
                if(s==arr[i]){
                    f = true;
                }
                else{
                    if(hm[s]){
                        f = true;
                    }
                }
                if(s.length()==3){
                    string s2 = s.substr(0,2);
                    if(hm[s2]>0){
                        f = true;
                    }
                }
                mx[arr[i][0]] = i;
                hm[arr[i]] = i;
            }
        }
        for(int i = 1; i<=n; i++){
            reverse(arr[i].begin(),arr[i].end());
        }
        reverse(arr.begin()+1,arr.end());
        if(true){
            map<string,int>hm;
            vector<int>mx(1000);
                for(int i = 1; i<=n; i++){
                string s = arr[i];
                reverse(s.begin(),s.end());
                if(s==arr[i]){
                    f = true;
                }
                else{
                    if(hm[s]){
                        f = true;
                    }
                }
                if(s.length()==3){
                    string s2 = s.substr(0,2);
                    if(hm[s2]>0){
                        f = true;
                    }
                }
                mx[arr[i][0]] = i;
                hm[arr[i]] = i;
            }
        }
        if(f)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}