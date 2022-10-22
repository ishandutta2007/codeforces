#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;cin >> q;
    while(q--){
        int a,b,n,S;
        cin >> a >> b >> n >> S;
        int t = min(a,S/n);
        S -= t*n;
        if (b >= S) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}