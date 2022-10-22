#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        long s,res = 0;
        cin >> s;
        while(s >= 10){
            res += s-s%10;
            s = s/10 + s%10;
        }
        res += s;
        cout << res << endl;
    }
    return 0;
}