#include <bits/stdc++.h>
using namespace std;
int main(){
    long long r;
    cin >> r;
    r--;
    long long x = 1, y;
    for ( ; x*x < r; x++){
        if ((r % x == 0) && ((r/x - x) % 2 == 1) && (r/x-x-1 >= 2)){
            y = (r/x-x-1)/2;
            return cout << x << ' ' << y, 0;
        }
    }
    cout << "NO";
    return 0;
}