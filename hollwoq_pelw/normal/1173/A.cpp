#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z;
    cin >> x >> y >> z;
    int mx = x-y+z;
    int mn = x-y-z;
    if (mx == mn && mn == 0) cout << 0;
    else if (mn > 0) cout << '+';
    else if (mx < 0) cout << '-';
    else cout << '?';
    return 0;
}