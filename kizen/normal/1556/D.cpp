#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

int out(int op, int i, int j){
    if(op == 0) cout << "and " << i + 1 << ' ' << j + 1 << '\n';
    else cout << "or " << i + 1 << ' ' << j + 1 << '\n';
    cout.flush();
    int x; cin >> x;
    return x;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> oand(n), oor(n);
    int la;
    for(int i = 1; i < n; ++i){
        oand[i] = out(0, i - 1, i);
        oor[i] = out(1, i - 1, i);
    }
    la = out(0, n - 3, n - 1);
    vector<int> a(n);
    for(int i = 0; i <= 32; ++i){
        vector<int> chk(n), t(n, -1);
        for(int j = 1; j < n - 1; ++j){
            int val = (oand[j] >> i & 1) + (oor[j] >> i & 1) + (oand[j + 1] >> i & 1) + (oor[j + 1] >> i & 1);
            if(val >= 3){
                a[j] |= (1 << i);
                t[j] = 1;
                chk[j] = 1;
                if(j == 1){
                    if((oand[j] >> i & 1)) a[0] |= (1 << i);
                    chk[0] = 1;
                }
                if(j + 1 == n - 1){
                    if((oand[j + 1] >> i & 1)) a[n - 1] |= (1 << i);
                    chk[n - 1] = 1;
                }
            }
            else if(val <= 1){
                t[j] = 0;
                chk[j] = 1;
                if(j == 1){
                    if((oor[j] >> i & 1)) a[0] |= (1 << i);
                    chk[0] = 1;
                }
                if(j + 1 == n - 1){
                    if((oor[j + 1] >> i & 1)) a[n - 1] |= (1 << i);
                    chk[n - 1] = 1;
                }
            }
        }
        int foz = -1;
        for(auto&i:t) if(i != -1){
            foz = 1; break;
        }
        if(foz == -1){
            t[n - 1] = (la >> i & 1);
        }
        int now = -1;
        for(int j = n - 1; j >= 0; --j){
            if(t[j] != -1) now = t[j];
            if(!chk[j] && now != -1){
                a[j] |= (now << i);
            }
            if(now != -1) now ^= 1;
        }
        now = -1;
        for(int j = 0; j < n; ++j){
            if(t[j] != -1) now = t[j];
            if(!chk[j] && now != -1){
                a[j] |= (now << i);
            }
            if(now != -1) now ^= 1;
        }
    }
    sort(a.begin(), a.end());
    cout << "finish " << a[k - 1] << '\n'; cout.flush();
    return 0;
}