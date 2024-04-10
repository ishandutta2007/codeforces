#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, r;
        cin >> n >> r;
        int x[n];
        for (int i = 0; i < n; i ++) cin >> x[i];
        sort(x,x+n);
        int ans = 1;
        int l = n-1, f = 0, k = x[l];
        while(true){
            // kill the last monster
            while(x[l] == k){
                l--;
            }
            k = x[l];
            //push other to death
            while(f <= l && x[f] <= ans*r){
                f ++;
            }
            if (f > l) break;
            ans ++;
        }
        cout << ans << endl;
        
    }
    return 0;
}