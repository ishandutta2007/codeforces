#define x first
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int maxn = 5e2 + 88;
const int dx[] = {-1, 1};
const int dy[] = {-1, 1};

char grid[maxn][maxn];

void init(int n){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) grid[i][j] = '.';
}

void solve(){
    int n, k, r, c;
    cin >> n >> k >> r >> c;

    --r; --c;

    init(n);

    r %= k;
    c %= k;

    int cc = c;

    for(int i = r; i < n; ++i){
        for(int j = cc; j < n; j += k) grid[i][j] = 'X';
        cc = (cc + 1) % k;
    }

    cc = c;

    for(int i = r; i >= 0; --i){
        for(int j = cc; j < n; j += k) grid[i][j] = 'X';
        cc = (cc - 1 + k) % k;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j) cout << grid[i][j];
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}