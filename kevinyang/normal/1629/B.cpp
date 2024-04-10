#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int l,r,k;
        cin >> l >> r >> k;
        if(l==r){
            if(l==1)cout << "NO\n";
            else cout << "YES\n";
            continue;
        }
        int v = r/2-(l-1)/2;
        int v2 = r/3-(l-1)/3;
        if(k+v>=r-l+1||k+v2>=r-l+1)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}