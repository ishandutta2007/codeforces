#include <bits/stdc++.h>
using namespace std;
#define int long long
int fix(int i){
    i%=10; i+=10; i%=10;
    return i;
}
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
        for(int i = 0; i<n; i++){
            int k;
            cin >> k;
            string s;
            cin >> s;
            for(char nxt: s){
                if(nxt=='U')arr[i]--;
                else arr[i]++;
            }
            arr[i] = fix(arr[i]);
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}