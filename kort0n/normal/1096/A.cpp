#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int t;
    cin >> t;
    for(int time = 0; time < t; time++){
        ll x, y;
        cin >> x >> y;
        if(y % 2 == 1)y--;
        cout << y / 2 << " " << y << endl;
    }
    return 0;
}