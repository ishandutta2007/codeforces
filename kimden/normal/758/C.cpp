#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using ld = long double;

const ll MAXN = 1000000007;
ll a[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    ll n, m, k, x, y;
    ll add = 0;
    cin >> n >> m >> k >> x >> y;
    ll tmp = ((2 * n - 2) * m);
    if(n == 1){
        tmp = m;
    }
    add = k / tmp;
    k = k % tmp;
    ll mx = -9999, mn = 0;
    for(int i = 0; i < n; i++){
        ll cur = (i == 0 || i == n - 1) ? add : 2 * add;
        for(int j = 0; j < m; j++){
            a[i][j] = cur;
        }
    }
    mx = 2 * add;
    if(n <= 2){
        mx = add;
    }
    mn = add;
    int i = 0, j = 0;
    bool dir = false;
    while(k){
        a[i][j]++;
        mx = max(mx, a[i][j]);
        k--;
        j++;
        if(j == m){
            j = 0;
            if(dir){
                i--;
            }else{
                i++;
                if(i >= n){
                    i = n - 2;
                    dir = true;
                    mn++;
                }
            }
        }
    }
    ll ser = a[x - 1][y - 1];
    cout << mx << " " << mn << " " << ser << endl;
    return 0;
}