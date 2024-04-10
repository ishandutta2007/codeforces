#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,a[3],t;
    cin >> t;
    while(t){
        t--;
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        r = a[2]-a[0]-2;
        if (r <= 0) cout << 0 << endl;
        else cout << 2*r << endl;
    }
    return 0;
}