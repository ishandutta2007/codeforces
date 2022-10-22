#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    if(k == 0){cout << "0 0"; return 0;}
    if(k == n){cout << "0 0"; return 0;}
    cout << "1 ";
    int treba = 1+(n-2)/3;
    if(treba == k){
        if(n%3 == 1){cout << k*2; return 0;}
    }
    if(k >= treba){cout << n-k; return 0;}
    else cout << 2*k;
    return 0;
}