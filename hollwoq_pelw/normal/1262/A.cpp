#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        long l,r,n,maxl=-1,minr=-1;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> l >> r;
            if (maxl < l || maxl == -1) maxl = l;
            if (minr > r || minr == -1) minr = r;
        }
        if (maxl < minr) cout << 0 << endl;
        else cout << maxl-minr << endl;
    }
    return 0;
}