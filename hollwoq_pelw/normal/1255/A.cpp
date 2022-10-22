#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        long a,b;
        cin >> a >> b;
        long s = abs(a-b);
        long res = (s/5) + (s%5)/2 + (s%5)%2;
        cout << res << endl;
    }
    return 0;
}