#include <bits/stdc++.h>
using namespace std;
int main(){
    long long x,y,z,s;
    cin >> x >> y >> z;
    cout << (x+y)/z << ' ';
    x%=z;
    y%=z;
    s=(x+y)%z;
    if (x+y==s) cout << 0;
    else cout << min(abs(s-x), abs(s-y));
}