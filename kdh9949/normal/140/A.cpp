#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, R, r;
    cin >> n >> R >> r;
    if(n == 1){
        cout << (R >= r ? "YES" : "NO");
        return 0;
    }
    bool flag = ((R - r) * sin(3.1415926535 / n) + 1e-7 > r);
    cout << (flag ? "YES" : "NO");
}