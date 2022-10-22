#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int a = 0, b = 0, c = 0;
        a = n / 3;
        if (n % 3 == 1) {
            a -= 2;
            c ++;
        }else if (n % 3 == 2){
            a --;
            b ++;
        }
        if (a < 0){
            cout << -1 << endl;
        }else{
            cout << a << ' ' << b << ' ' << c << endl;
        }
    }
}