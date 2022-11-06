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
            arr[i] = i;
        }
        reverse(arr.begin()+1,arr.end());
        for(int i = 1; i<=n; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        for(int i = 2; i<=n; i++){
            swap(arr[i],arr[i-1]);
            for(int i = 1; i<=n; i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
            swap(arr[i],arr[i-1]);
        }
    }
    return 0;
}