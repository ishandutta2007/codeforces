#include <bits/stdc++.h>
using namespace std;
int t,r,c,x,y;
int main(){
    cin >> t;
    while(t--){
        cin >> r >> c >> x >> y;
        cout << max(r*(max(y,c-1-y)),c*(max(x,r-1-x)))<<"\n";
    }
    return 0;
}