#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long x,y,z;
        cin >> x >> y;
        z = x-y;
        if (z <= 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}