#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MAX = 1000000000000000000LL;

vector <ll> vals[2];
ll p[20];
ll lim;
int _n;

void gen(ll val, int ind){
    if(ind > _n){
        vals[ind%2].push_back(val);
        return;
    }
    if(lim/val >= p[ind]){
        gen(val*p[ind], ind);
    }
    gen(val, ind + 2);
}

ll check(int n, ll k){
    ll res = 0;
    _n = n;
    int j = 0;
    ll sled = k/vals[1][0];
    for(int i=int(vals[0].size())-1; i>=0; i--){
        while(j < vals[1].size() && sled >= vals[0][i]){
            j++;
            if(j < vals[1].size()) sled = k/vals[1][j];
        }
        res += j;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i];
    ll k;
    cin >> k;
    ll l = 1, r = MAX, res = MAX;
    _n = n;
    lim = MAX;
    gen(1, 1);
    gen(1, 2);
    sort(vals[0].begin(), vals[0].end());
    sort(vals[1].begin(), vals[1].end());
    while(l <= r){
        ll mid = (l+r)/2;
        if(check(n, mid) >= k){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res << "\n";
    return 0;
}