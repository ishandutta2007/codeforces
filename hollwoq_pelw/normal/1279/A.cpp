#include <bits/stdc++.h>
using namespace std;
int main(){
    signed long long t,r,g,b,m;
    cin >> t;
    while(t){
        t--;
        cin >> r >> g >> b;
        m = r;
        if (m < g) m = g;
        if (m < b) m = b;
        if (2*m>r+g+b+1) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}