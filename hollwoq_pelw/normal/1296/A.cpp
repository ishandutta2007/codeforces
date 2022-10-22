#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        int n,ce=0,co=0,k;
        cin >> n;
        while(n){
            n--;
            cin >> k;
            if (k % 2 == 0) ce ++;
            else co ++;
        }
        if (co == 0 || (ce == 0 && co % 2 == 0)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}