#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    int x, y, a, b, c, d;
    cin >> a >> b >> c >> d >> x >> y;
    if((a - c) % x == 0 && (b - d) % y == 0 && (abs(a - c) / x + abs(b - d) / y) % 2 == 0 ){
        cout << "YES" << endl;
    }else{

        cout << "NO" << endl;
    }


    return 0;
}