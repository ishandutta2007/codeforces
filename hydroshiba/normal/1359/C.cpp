#include "bits/stdc++.h"
using namespace std;

const int inf = INT_MAX / 2;

double f(long long x, long long a, long long b){
    return double((x / 2) * (a + b) + (x % 2) * a) / double(x);
}

double g(long long x, long long a, long long b, long long t){
    double res = f(x, a, b) - t;
    if(res < 0) res = -res;

    return res;
}

long long pos(long long x){
    return 2 * x - 1;
}

void solve(){
    long long a, b, t;
    cin >> a >> b >> t;

    double diff = t - ((a + b) / 2.0);

    long long ans = 0;
    for(long long step = inf / 2; step > 0; step /= 2){
        while(pos(ans + step) < inf && g(pos(ans + step), a, b, t) > g(pos(ans + step + 1), a, b, t))
            ans += step;
    }

    if(g(pos(ans + 1), a, b, t) < diff) cout << pos(ans + 1);
    else cout << 2;

    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}