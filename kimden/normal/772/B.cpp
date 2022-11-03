#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 1024;
int x[MAXN], y[MAXN];
ld dist[MAXN]; // dist[i]: i -> i+1
ld dist2[MAXN]; // i -> i + 2

int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; ++i){
        dist[i] = hypot((ld)(x[(i + 1) % n] - x[i]), (ld)(y[(i + 1) % n] - y[i]));
        dist2[i] = hypot((ld)(x[(i + 2) % n] - x[i]), (ld)(y[(i + 2) % n] - y[i]));
    }
    ld ans = 2e35;
    for(int i = 0; i < n; ++i){
        int j = i + 1;
        if(j >= n){
            j -= n;
        }
        int k = j + 1;
        if(k >= n){
            k -= n;
        }
        ld ax = x[j] - x[i];
        ld ay = y[j] - y[i];
        ld bx = x[k] - x[j];
        ld by = y[k] - y[j];
        ld cx = x[k] - x[i];
        ld cy = y[k] - y[i];
        ld ad = dist[i];
        ld bd = dist[j];
        ld cd = dist2[i];
        ld ha = fabsl(ax * by - ay * bx) / ad;
        ld hb = fabsl(ax * by - ay * bx) / bd;
        ld hc = fabsl(cx * by - cy * bx) / cd;
        ld h = min(min(ha, hb), hc);
        ans = min(ans, h);
    }
    ans = ans / 2;
    cout << setprecision(17) << fixed << ans << endl;
}