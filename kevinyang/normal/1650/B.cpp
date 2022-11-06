#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int l,r,a;
        cin >> l >> r >> a;
        int v = (r+1)/a*a-1;
        if(v<l)v = 0;
        cout << max(r/a+r%a,v/a+v%a) << "\n";
    }
    return 0;
}