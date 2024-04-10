#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        int n,k = -1;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (i > 0){
                if ( abs(a[i-1]-a[i]) >= 2){
                    k = i;
                } 
            }
        }
        if (k == -1) cout << "NO" << endl;
        else cout << "YES" << endl << k << ' ' << k+1 << endl;
        
    }
    return 0;
}