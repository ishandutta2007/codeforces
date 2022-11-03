#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;



int main() {
    int n, m, x, y, a, b;
    cin >> n >> m >> x >> y >> a >> b;
    int ans = 1000000000;
    if(n == 1 || m == 1){
        if((x == 1 || x == n) && (y == 1 || y == m)){
            ans = 0;
        }
        if(ans == 1000000000){
            cout << "Poor Inna and pony!" << endl;
        }else {
            cout << ans << endl;
        }
        return 0;
    }
    for(int xx = 1; xx <= n; xx += n - 1){
        for(int yy = 1; yy <= m; yy += m - 1){
            if((xx - x) % a != 0 || (yy - y) % b != 0){
                continue;
            }
            int xxx = abs(xx - x) / a;
            int yyy = abs(yy - y) / b;
            if((xxx + yyy) % 2 != 0){
                continue;
            }
            if(xxx == 0 && yyy == 0){
                ans = 0;
                continue;
            }
            if(xxx == 0){
                if(xx == 1){
                    if(xx + a <= n){
                        ans = min(ans, yyy);
                    }
                }else{
                    if(xx - a >= 1){
                        ans = min(ans, yyy);
                    }
                }
            }else if(yyy == 0){
                if(yy == 1){
                    if(yy + b <= m){
                        ans = min(ans, xxx);
                    }
                }else{
                    if(yy - b >= 1){
                        ans = min(ans, xxx);
                    }
                }
            }else{
                ans = min(ans, max(xxx, yyy));
            }

        }
    }
    if(ans == 1000000000){
        cout << "Poor Inna and pony!" << endl;
    }else {
        cout << ans << endl;
    }
}