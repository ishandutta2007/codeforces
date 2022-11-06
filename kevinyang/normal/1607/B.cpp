#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int x,n;
        cin >> x >> n;
        for(int i = n/4*4+1; i<=n; i++){
            if(x%2!=0)x+=i;
            else x-=i;
        }
        cout << x << "\n";
    }
    return 0;
}