#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        int a,b;
        cin >> a >> b;
        if (a >= b) {cout << "YES" << endl; continue;}
        if (a == 1 || a == 3) {cout << "NO" << endl; continue;}
        if (a == 2){
            if (b == 3) {cout << "YES" << endl; continue;}
            else {cout << "NO" << endl; continue;}
        }
        cout << "YES" << endl;
    }
    return 0;
}