#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int maxn = 2e5 + 88;
const int maxl = 19;
const int inf = INT_MAX / 2;

int num[maxn][maxl];

void solve(){
    int l, r;
    cin >> l >> r;

    int ans = inf;
    for(int i = 0; i < maxl; ++i){
        ans = min(ans, num[r][i] - num[l - 1][i]);
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; ++i){
        for(int j = 0; j < maxl; ++j){
            num[i][j] = num[i - 1][j] + !((i >> j) & 1);
        }
    }

    int t;
    cin >> t;

    while(t--)
        solve();
}