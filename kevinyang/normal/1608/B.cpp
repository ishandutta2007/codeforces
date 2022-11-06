#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin >> n >> a >> b;
        if(abs(a-b)>1||a+b>n-2){
            cout << "-1\n";
            continue;
        }
        vector<int>arr(n+1);
        int left = 1; int right = n;
        for(int i = 1; i<=n; i++){
            if(i%2==1){
                arr[i] = left; left++;
            }
            else{
                arr[i] = right; right--;
            }
        }
        if(a<b){
            for(int i = 1; i<=n; i++){
                arr[i] = n-arr[i]+1;
            }

        }
        sort(arr.begin()+a+b+2,arr.end());
        if(abs(arr[a+b+2]-arr[a+b+1])>1){
            reverse(arr.begin()+a+b+2,arr.end());
        }
        for(int i = 1; i<=n; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}