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
        vector<int>a(n+1);
        for(int i = 1; i<=n; i++){
            cin >> a[i];
        }
        bool f = true;
        for(int i = 2; i<n; i++){
            if(a[i]%__gcd(a[i-1],a[i+1])==0)continue;
            f = false;
        }
        if(f)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}