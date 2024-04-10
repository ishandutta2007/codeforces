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
        n--;
        if(n%2==1){
            cout << 2 << " " << n-2 << " " << "1\n";
        }
        else{
            int v = n/2;
            if(v%2==1)
                cout << v-2 << " " << v+2 << " " << "1\n";
            else
                cout << v-1 << " " << v+1 << " " << "1\n";
        }
    }
    return 0;
}