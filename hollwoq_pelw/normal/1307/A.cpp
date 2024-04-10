#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while (t--){
        int n,d,k,r = 0;
        cin >> n >> d;
        for (int i = 0; i < n; i++){
            cin >> k;
            if (i == 0) r += k;
            else{
                int t = min(d/i, k);
                r += t;
                d -= t*i;
            }
        }
        cout << r << endl;
    }
    return 0;
}