#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,x,y;
        cin >> n >> x >> y;
        for(int i = 1; i<=n; i++){
            int v;
            cin >> v;
            if(v%2==1){
                x++;
            }
        }
        if(x%2==y%2){
            cout << "Alice\n";
        }
        else{
            cout << "Bob\n";
        }
    }
    return 0;
}