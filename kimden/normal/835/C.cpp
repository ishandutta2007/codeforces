#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int n, q, c;



int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> q >> c;
    int a[11][100][100];
    for(int i = 0; i < 11; ++i){
        for(int j = 0; j < 100; ++j){
            for(int k = 0; k < 100; ++k){
                a[i][j][k] = 0;
            }
        }
    }
    vector<int> x, y, s;
    x.resize(n);
    y.resize(n);
    s.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i] >> s[i];
        --x[i];
        --y[i];
        for(int j = 0; j < c + 1; ++j){
            a[j][x[i]][y[i]] += (s[i] + j) % (c + 1);
        }
    }
    for(int i = 0; i < c + 1; ++i){
        for(int j = 0; j < 100; ++j){
            for(int k = 1; k < 100; ++k){
                a[i][j][k] += a[i][j][k - 1];
            }
        }
    }
    int t, qq, w, e, r;
    for(int i = 0; i < q; ++i){
        cin >> t >> qq >> w >> e >> r;
        t %= c + 1;
        --qq;
        --w;
        --e;
        --r;
        int ans = 0;
        for(int j = qq; j <= e; ++j){
            if(w == 0){
                ans += a[t][j][r];
            }else{
                ans += a[t][j][r] - a[t][j][w - 1];
            }
        }
        cout << ans << endl;
    }
    return 0;
}