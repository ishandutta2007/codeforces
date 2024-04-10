#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;

vector<int> v, k, x;
vector<int> pos[75];
ll dp[76][76][76][2];

int moveV(int vv, int kk, int xx){
    int idx = v[vv - 1];
    return vv + kk + xx - 1 - (vv - 1 + min(kk, pos[idx][1]) + min(xx, pos[idx][2]));
}
int moveK(int vv, int kk, int xx){
    int idx = k[kk - 1];
    return vv + kk + xx - 1 - (kk - 1 + min(vv, pos[idx][0]) + min(xx, pos[idx][2]));
}
int moveX(int vv, int kk, int xx){
    int idx = x[xx - 1];
    return vv + kk + xx - 1 - (xx - 1 + min(kk, pos[idx][1]) + min(vv, pos[idx][0]));
}

ll get(int vv, int kk, int xx, int isv){
    if(dp[vv][kk][xx][isv]){
        return dp[vv][kk][xx][isv] - 1;
    }
    ll ans = 9000000000000000000LL;
    if(vv == 0 && kk == 0 && xx == 0){
        dp[vv][kk][xx][isv] = 1;
        return 0;
    }
    if(vv > 0 && isv){
        ans = min(ans, get(vv - 1, kk, xx, 0) + moveV(vv, kk, xx));
        ans = min(ans, get(vv - 1, kk, xx, 1) + moveV(vv, kk, xx));
    }
    if(kk > 0 && !isv){
        ans = min(ans, get(vv, kk - 1, xx, 0) + moveK(vv, kk, xx));
    }
    if(xx > 0 && !isv){
        ans = min(ans, get(vv, kk, xx - 1, 0) + moveX(vv, kk, xx));
        ans = min(ans, get(vv, kk, xx - 1, 1) + moveX(vv, kk, xx));
    }
    dp[vv][kk][xx][isv] = ans + 1;
    return ans;
}

int main() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; ++i){
        switch(s[i]){
            case 'V':
                v.push_back(i);
                break;
            case 'K':
                k.push_back(i);
                break;
            default:
                s[i] = 'X';
                x.push_back(i);
                break;
        }
        pos[i] = {v.size(), k.size(), x.size()};
    }
    cout << min(get(v.size(), k.size(), x.size(), 0), get(v.size(), k.size(), x.size(), 1)) << endl;
}