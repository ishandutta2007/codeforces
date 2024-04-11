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
    while(t--){
        int n, x, y, d;
        cin >> n >> x >> y >> d;
        int ans = INF;
        int delta = abs(x - y);
        if(delta % d == 0){
            ans = delta / d;
        }
        delta = y - 1;
        if(delta % d == 0){
            ans = min(ans, delta / d + (x - 1 + d - 1) / d);
        }
        delta = n - y;
        if(delta % d == 0){
            ans = min(ans, delta / d + (n - x + d - 1) / d);
        }
        if(ans == INF) ans = -1;
        cout << ans << endl;
    }
    return 0;
}