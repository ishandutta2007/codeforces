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
        for(int nxt: arr){
            s.insert(nxt);
        }
        sort(arr.begin(),arr.end());
        if(arr[n-1]%3==2){
            bool f = false;
            for(int i = 0; i<n; i++){
                if(arr[i]%3==1)f = true;
            }
            cout << arr[n-1]/3+1+f << "\n";
        }
        else if(arr[n-1]%3==1){
            if(s.find(arr[n-1]-1)==s.end()&&s.find(1)==s.end()){
                cout << arr[n-1]/3+1 << "\n";
            }
            else{
                bool f =false;
                for(int i = 0; i<n; i++){
                    if(arr[i]%3==2)f = true;
                }
                cout << arr[n-1]/3+1+f << "\n";
            }
        }
        else{
            bool f = false;
            for(int i = 0; i<n; i++){
                if(arr[i]%3!=0)f = true;
            }
            cout << arr[n-1]/3 +f << "\n";
        }
    }
    return 0;
}