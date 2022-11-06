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
        cout << (n+1)/2 << "\n";
        int x = 1; int y = 3*n-1;
        for(int i = 0; i<(n+1)/2; i++){
            cout << x << " " << y << "\n";
            x+=3;
            y-=3;
        }
    }
    return 0;
}