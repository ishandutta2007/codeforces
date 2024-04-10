#include "bits/stdc++.h"
using namespace std;

const int maxn = 288;
long long arr[maxn][maxn];

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) cin >> arr[i][j];

    long long ans = LLONG_MIN;

    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
        long long sum = arr[i][j];

        int x = i;
        int y = j;
        while(x >= 0 && x < n && y >= 0 && y < m) sum += arr[x++][y++];

        x = i;
        y = j;
        while(x >= 0 && x < n && y >= 0 && y < m) sum += arr[x--][y--];

        x = i;
        y = j;
        while(x >= 0 && x < n && y >= 0 && y < m) sum += arr[x++][y--];

        x = i;
        y = j;
        while(x >= 0 && x < n && y >= 0 && y < m) sum += arr[x--][y++];

        sum -= arr[i][j];
        sum -= arr[i][j];
        sum -= arr[i][j];
        sum -= arr[i][j];

        ans = max(ans, sum);
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}