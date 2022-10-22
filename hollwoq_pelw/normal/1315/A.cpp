#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,x,y;
        cin >> a >> b >> x >> y;
        cout << max(a*max(y, b-y-1), b*max(x, a-x-1)) << endl;
    }
    return 0;
}