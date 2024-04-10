#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m && n) {
        vector<double> w(n);
        REP(i, n) cin >> w[i];
        double ans = 0;
        REP(i, m) {
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--;
            ans = max(ans, (w[a] + w[b]) / c);
        }
        printf("%.12f\n", ans);
    }
    return 0;
}