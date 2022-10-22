#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        int m = min(b,c/2);
        b -= m;
        int s = min(b/2,a);
        cout << (m+s)*3 << endl;
    }
}