#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        int n,k1,k2,m1=-1,m2=-1,a1,a2;
        cin >> n >> k1 >> k2;
        while(k1){
            k1--;
            cin >> a1;
            if (a1 > m1) m1 = a1;
        }
        while(k2){
            k2--;
            cin >> a2;
            if (a2 > m2) m2 = a2;
        }
        if (m1 > m2){
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}