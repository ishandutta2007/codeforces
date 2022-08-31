#include <bits/stdc++.h>
using namespace std;
#define ll long long    

int main(){
    ll a, b;
    cin >> a >> b;
    while(1){
        if(a == 0 || b == 0) break;
        if(a < 2 * b && b < 2 * a) break;
        if(a >= 2 * b) {
            a %= (2 * b);
        }
        else if(b >= 2 * a) b %= (2 * a);
    }
    cout <<a << " " << b << endl;
}