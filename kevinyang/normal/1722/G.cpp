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
        int x = (int)1e8;
        vector<int>arr;
        int a = 0;
        for(int i = 0; i<n/4*4; i++){
            arr.push_back(i+4);
            a^=arr[i];
        }
        if(n%4==1){
            arr.push_back(0);
        }
        else if(n%4==2){
            arr[arr.size()-1] = x;
            int sum = 0;
            for(int nxt: arr){
                sum^=nxt;
            }
            arr.push_back(sum);
            arr.push_back(0);
        }
        else{
            arr.push_back(1);
            arr.push_back(2);
            arr.push_back(3);
        }
        for(int i = 0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}