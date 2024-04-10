#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, t;
    cin >> n >> t;
    int ans = 1e17, ii = 1;
    for(int i = 1;i <= n;i++){
        int a, b;
        cin >> a >> b;
        if(a >= t){
            if(ans > a){
                ans = a;
                ii = i;
            }
            continue;
        }
        int z = (t - a + b - 1) / b;
        int u = a + b * z;
        if(u < ans){
            ans = u;
            ii=i;
        }
    }
    cout << ii;
}