#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<ll>> a(2, vector<ll>(n));
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    if(n == 1){
        cout << a[1][0] << endl;
        return 0;
    }
    ll ans;
    ll cur, tm, cur2;
    cur = 0;
    tm = 0;
    for(int i = 0; i < n; ++i){
        if(i % 2 == 0){
            cur += a[0][i] * (tm++);
            cur += a[1][i] * (tm++);
        }else{
            cur += a[1][i] * (tm++);
            cur += a[0][i] * (tm++);
        }
    }
    ans = cur;
    cur2 = cur;
    ll rightcnt = 3;
    int z = (n % 2 == 0 ? 1 : 0);
    ll rightsum = a[0][n - 1] + a[1][n - 1] + a[z][n - 2];
    for(int i = n - 4; i >= 0; i -= 2){
        cur -= 2 * rightsum;
        cur += (rightcnt + 1) * a[1 - z][i + 1];
        cur += (rightcnt - 1) * a[1 - z][i + 2];
        rightcnt += 4;
        rightsum += a[1 - z][i + 1] + a[1 - z][i + 2] + a[z][i] + a[z][i + 1];
        ans = max(ans, cur);
    }
    cur2 += 2 * (a[z][n - 2] - a[1 - z][n - 1]);
    ans = max(ans, cur2);
    cur = cur2;
    if(n >= 3) {
        rightsum = a[0][n - 1] + a[0][n - 2] + a[1][n - 1] + a[1][n - 2] + a[1 - z][n - 3];
        rightcnt = 5;
        for (int i = n - 5; i >= 0; i -= 2) {
            cur -= 2 * rightsum;
            cur += (rightcnt + 1) * a[z][i + 1];
            cur += (rightcnt - 1) * a[z][i + 2];
            rightcnt += 4;
            rightsum += a[z][i + 1] + a[z][i + 2] + a[1 - z][i] + a[1 - z][i + 1];
            ans = max(ans, cur);
        }
    }
    cur = 0;
    tm = 0;
    for(int i = 0; i < n; ++i){
        cur += a[0][i] * (tm++);
    }
    for(int i = n - 1; i >= 0; --i){
        cur += a[1][i] * (tm++);
    }
    ans = max(ans, cur);
    cout << ans << endl;
}