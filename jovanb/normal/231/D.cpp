#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int x, y, z;
    cin >> x >> y >> z;
    int x1, y1, z1;
    cin >> x1 >> y1 >> z1;
    int a1, a2, a3, a4, a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    int zbir=0;
    if(y < 0) zbir += a1;
    if(y > y1) zbir += a2;
    if(z < 0) zbir += a3;
    if(z > z1) zbir += a4;
    if(x < 0) zbir += a5;
    if(x > x1) zbir += a6;
    cout << zbir;
    return 0;
}