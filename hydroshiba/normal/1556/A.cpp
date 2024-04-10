#include "bits/stdc++.h"
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        
        if(a == 0 && b == 0) cout << 0;
        else if(abs(a - b) % 2 == 1) cout << -1;
        else if(a == b) cout << 1;
        else cout << 2;
        cout << '\n';
    }
}