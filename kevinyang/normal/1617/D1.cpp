#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int fix(int x){
    if(x>n){
        return x-n;
    }
    return x;
}
int check(int i){
    cout << "? " << fix(i) << " " << fix(i+1) << " " << fix(i+2) << endl;
    int v;
    cin >> v;
    return v;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int>arr(2*n+1);
        for(int i = 1; i<=n; i++){
            arr[i] = check(i);
        }
        for(int i = n+1; i<=2*n; i++){
            arr[i] = arr[i-n];
        }
        vector<int>ans(n+1);//crew = -1 impostor = 1
        vector<int>sum(2*n+1);//sum[i] = sum of ans[i]+ans[i+1]+ans[i+2]
        for(int i = 1; i<=n; i++){
            if(arr[i]==1&&arr[fix(i+1)]==0){
                ans[i] = -1; ans[fix(i+3)] = 1;
                for(int j = 1; j<=n; j++){
                    if(i==j||fix(i+3)==j){
                        continue;
                    }
                    cout << "? " << i << " " << fix(i+3) << " " << j << endl;
                    int v;
                    cin >> v;
                    if(v==0){
                        ans[j] = 1;
                    }
                }
                break;
            }
            if(arr[i]==0&&arr[fix(i+1)]==1){
                ans[i] = 1; ans[fix(i+3)] = -1;
                for(int j = 1; j<=n; j++){
                    if(i==j||fix(i+3)==j){
                        continue;
                    }
                    cout << "? " << i << " " << fix(i+3) << " " << j << endl;
                    int v;
                    cin >> v;
                    if(v==0){
                        ans[j] = 1;
                    }
                }
                break;
            }
        }
        int k = 0;
        vector<int>vals;
        for(int i = 1; i<=n; i++){
            if(ans[i]==1){
                k++;
                vals.push_back(i);
            }
        }
        assert(k!=0);
        cout << "! " << k << " ";
        for(int i = 0; i<vals.size(); i++){
            cout << vals[i];
            if(i<vals.size()-1)cout << " ";
        }
        cout << endl;
    }
    return 0;
}