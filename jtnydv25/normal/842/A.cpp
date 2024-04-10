#include <bits/stdc++.h>
using namespace std;
int main(){
    int l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    for(int i = x; i <= y; i++){
        long long z = i * 1ll * k;
        if(z >= l && z <= r){
            cout << "YES"; return 0;
        }
    }
    cout << "NO";
}