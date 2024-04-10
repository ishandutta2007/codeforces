#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll br3[3], br2[3];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    ll a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    ll x = a1, y = b1, z = a2, k = b2;
    while(x%3 == 0){
        br3[1]++;
        x /= 3;
    }
    while(x%2 == 0){
        br2[1]++;
        x /= 2;
    }
    while(y%3 == 0){
        br3[1]++;
        y /= 3;
    }
    while(y%2 == 0){
        br2[1]++;
        y /= 2;
    }
    while(z%3 == 0){
        br3[2]++;
        z /= 3;
    }
    while(z%2 == 0){
        br2[2]++;
        z /= 2;
    }
    while(k%3 == 0){
        br3[2]++;
        k /= 3;
    }
    while(k%2 == 0){
        br2[2]++;
        k /= 2;
    }
    if(x*y != z*k){cout << -1; return 0;}
    ll br = 0;
    while(br3[1] > br3[2]){
        br++;
        br3[1]--;
        br2[1]++;
        if(a1%3 == 0) {a1 /= 3; a1 *= 2;}
        else {b1 /= 3; b1 *= 2;}
    }
    while(br3[2] > br3[1]){
        br++;
        br3[2]--;
        br2[2]++;
        if(a2%3 == 0) {a2 /= 3; a2 *= 2;}
        else {b2 /= 3; b2 *= 2;}
    }
    while(br2[1] > br2[2]){
        br2[1]--;
        br++;
        if(a1%2 == 0) a1 /= 2;
        else b1 /= 2;
    }
    while(br2[2] > br2[1]){
        br++;
        br2[2]--;
        if(a2%2 == 0) a2 /= 2;
        else b2 /= 2;
    }
    cout << br << endl << a1 << " " << b1 << endl << a2 << " " << b2;
    return 0;
}