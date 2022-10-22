#include <bits/stdc++.h>
using namespace std;
int main(){
    int q, l, r, d;
    cin >> q;
    while(q--){
        cin >> l >> r >> d;
        if (l <= d) cout << (r/d+1)*d;
        else cout << d;
        cout << endl;
    }
    return 0;
}