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
        string s;
        cin >> s;
        if(s[0]<'9'){
            for(int i = 0; i<n; i++){
                cout << (int)('9'-s[i]);
            }
            cout << "\n";
        }
        else{
            reverse(s.begin(),s.end());
            vector<int>arr(n+1,1);
            for(int i = 0; i<=n; i++){
                int v = s[i]-'0';
                if(arr[i]>=v){
                    arr[i]-=v;
                }
                else{
                    arr[i+1]--;
                    arr[i]+=10;
                    arr[i]-=v;
                }
            }
            for(int i = n-1; i>=0; i--){
                cout << arr[i];
            }
            cout << "\n";
        }
    }
    return 0;
}