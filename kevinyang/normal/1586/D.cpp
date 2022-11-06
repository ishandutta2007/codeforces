#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    //find value of last element
    vector<int>ans(n+1);
    int val = 0;
    for(int i = n; i>=1; i--){
        if(i==1){
            ans[n] = 1;
            val = 1;
            break;
        }
        vector<int>arr(n+1,n);
        arr[n] = n-i+1;
        cout << "? ";
        for(int i = 1; i<=n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        int x;
        cin >> x;
        if(x>0){
            ans[n] = i;
            val = i;
            break;
        }
    }
    for(int i = 1; i<=n; i++){
        if(i==val)continue;
        vector<int>arr(n+1,n+1-i);
        arr[n] = n+1-val;
        cout << "? ";
        for(int i = 1; i<=n; i++){
            cout << arr[i]<< " ";
        }
        cout << endl;
        int x;
        cin >> x;
        ans[x] = i;
    }
    cout << "! ";
    for(int i = 1; i<=n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}