#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    long n, k, x, res=0, i;
    cin>> n >> k;
    for(i=0; i<n; i++){
        cin >> x;
        if(k%x == 0) res = max(res, x);
    }
    cout << k/res;
    return 0;
}