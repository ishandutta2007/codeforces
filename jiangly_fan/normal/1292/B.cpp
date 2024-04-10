#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
LL x[maxn], y[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL ax, ay, bx, by;
    LL xs, ys, t;
    cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    int n = 0;
    for(int i = 1; ; i += 1){
        x[i] = x[i - 1] * ax + bx;
        y[i] = y[i - 1] * ay + by;
        if(max(x[i] - xs, 0LL) + max(y[i] - ys, 0LL) > t) break;
        n += 1;
    }
    int ans = 0;
    for(int i = 0; i <= n; i += 1)
        for(int j = 0; j <= n; j += 1){
            if(abs(xs - x[i]) + abs(ys - y[i]) + abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t) ans = max(ans, abs(j - i) + 1);
        }
    cout << ans;
    return 0;
}