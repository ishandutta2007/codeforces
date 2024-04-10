#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

const int mod = 998244353;

int pw(int x, int y, int mod){
    if(!y) return 1;
    if(y % 2) return pw(x, y - 1, mod) * x % mod;
    int val = pw(x, y / 2, mod);
    return val * val % mod;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    int xcnt = 1, ycnt = 1;
    vector<vector<int>> xchk(n + 1, vector<int>(2)), ychk(m + 1, vector<int>(2));
    int xno = 0, yno = 0;
    for(int i = 1; i <= n; ++i){
        xcnt = (xcnt * 2) % mod;
    }
    for(int i = 1; i <= m; ++i){
        ycnt = (ycnt * 2) % mod;
    }
    int i2 = pw(2, mod - 2, mod);
    vector<int> zo = {0, 0};
    map<pair<int, int>, int> mp;
    while(q--){
        int x, y, typ; cin >> x >> y >> typ;
        int bef = mp[make_pair(x, y)];
        if((typ == -1 && bef) || bef){
            --bef;
            --xchk[x][(y % 2 ^ bef)], --ychk[y][(x % 2 ^ bef)];
            --zo[(x + y) % 2 ^ bef];
            if(ychk[y][(x % 2 ^ bef) ^ 1] && !ychk[y][(x % 2 ^ bef)]){
                --yno;
            }
            if(!ychk[y][0] && !ychk[y][1]){
                ycnt = (ycnt * 2) % mod;
            }
            if(xchk[x][(y % 2 ^ bef) ^ 1] && !xchk[x][(y % 2 ^ bef)]){
                --xno;
            }
            if(!xchk[x][0] && !xchk[x][1]){
                xcnt = (xcnt * 2) % mod;
            }
            mp[make_pair(x, y)] = 0;
        }
        if(typ != -1){
            if(!xchk[x][0] && !xchk[x][1]){
                xcnt = (xcnt * i2) % mod;
            }
            if(xchk[x][(y % 2 ^ typ) ^ 1] && !xchk[x][(y % 2 ^ typ)]){
                ++xno;
            }
            if(!ychk[y][0] && !ychk[y][1]){
                ycnt = (ycnt * i2) % mod;
            }
            if(ychk[y][(x % 2 ^ typ) ^ 1] && !ychk[y][(x % 2 ^ typ)]){
                ++yno;
            }
            ++zo[(x + y) % 2 ^ typ];
            ++xchk[x][(y % 2 ^ typ)], ++ychk[y][(x % 2 ^ typ)];
            mp[make_pair(x, y)] = typ + 1;
        }
        int ans = 0;
        if(!xno) ans = (ans + xcnt) % mod;
        if(!yno) ans = (ans + ycnt) % mod;
        ans = (ans - !zo[0] - !zo[1] + mod) % mod;
        cout << ans << '\n';
    }
    return 0;
}