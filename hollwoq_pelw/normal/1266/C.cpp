#include <bits/stdc++.h>
using namespace std;
int main(){
    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1) {cout << 0; return 0;}
    
    for (int i = 1; i <= r; i ++){
        for (int j = 1; j <= c; j ++){
            if (r < c){
                cout << i*(j+r) << ' ';
            }else{
                cout << (i+c)*j << ' ';
            }
        }
        cout << "\n";
    }
    
    return 0;
}