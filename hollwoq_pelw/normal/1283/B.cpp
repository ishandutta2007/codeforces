#include <bits/stdc++.h>
using namespace std;
int main(){
    long t,n,k,r,m;
    cin >> t;
    while(t){
        t--;
        cin >> n >> k;
        r = n%k;
        if (r <= k/2){
            cout << n << endl;
        }else cout << n-r+k/2 << endl;
    }
    return 0;
}