#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        long a=-1,b=-1,c=-1,n;
        cin >> n;
        for (int i = 2; i < cbrt(n); i++){
            if (n%i == 0){
                a = i;
                n /= i;
                break;
            }
        }
        if (a == -1) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = a+1; i < sqrt(n); i++){
            if (n%i == 0){
                b = i;
                n /= i;
                break;
            }
        }
        if (b == -1){
            cout << "NO" << endl;
            continue;
        }
        c = n;
        cout << "YES" << endl << a << ' ' << b << ' ' << c << endl;
        
    }
    return 0;
}