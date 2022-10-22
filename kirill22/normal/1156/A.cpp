#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ;i < n;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0;i < n - 1;i++){
        if (a[i] == 2 && a[i + 1] == 3){
            cout << "Infinite";
            return 0;
        }
        if(a[i] == 3 && a[i + 1] == 2){
            cout << "Infinite";
            return 0;
        }
        if(a[i] == 1 && a[i + 1] == 2){
            if(i > 0){
                if(a[i - 1] == 3){
                    ans--;
                }
            }
            ans +=3;
        }
        if(a[i] == 1 && a[i + 1] == 3){
            ans +=4;
        }
        if(a[i] == 2 && a[i + 1] == 1){
            ans +=3;
        }
        if(a[i] == 3 && a[i + 1] == 1){
            ans +=4;
        }
    }
    cout << "Finite" << endl << ans;


}