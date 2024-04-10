#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int k;
    cin >> k;
    for(int i=19; k>0; i++){
        int x = i, z=0;
        while(x>0){
            z += x%10;
            x /= 10;
        }
        if(z == 10) k--;
        if(k == 0) {cout << i;return 0;}
    }
    return 0;
}