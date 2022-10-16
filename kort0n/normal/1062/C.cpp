#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
ll mod = 1e09 + 7;
    ll beki[1000050];
    ll sum[1000500];

int main() {
    //cout.precision(10);
    beki[0] = 1;
    for(int i = 1; i <= 1000000; i++){
        beki[i] = beki[i - 1] * 2;
        beki[i] = beki[i] % mod;
    }
    int n, q;
    cin >> n >> q;
    string field;
    cin >> field;
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1];
        if(field[i - 1] == '1'){
            sum[i]++;
        }
    }
    for(int now = 1; now <= q; now++){
        int l, r;
        cin >> l >> r;
        ll ans = 0;
        ans += beki[sum[r] - sum[l - 1]] - 1;
        ans = ans % mod;
        ll no = r - l + 1 - sum[r] + sum[l - 1];
        ans += (beki[sum[r] - sum[l - 1]] - 1) * (beki[no] - 1);
        ans = ans % mod;
        cout << ans << endl;
    }
    return 0;
}