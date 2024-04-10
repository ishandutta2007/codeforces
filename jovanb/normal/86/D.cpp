#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int BLOCK = 400;
const int MAXN = 200000;
const int MAXVAL = 1000000;

ll a[MAXN+5];

int cnt[MAXVAL+5];

struct query_{
    int l, r, ind;
    bool operator <(const query_ qr){
        if(l/BLOCK == qr.l/BLOCK) return r < qr.r;
        return l/BLOCK < qr.l/BLOCK;
    }
};

ll sol[MAXN+5];
vector <query_> queries;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, t;
    cin >> n >> t;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=t; i++){
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r, i});
    }
    sort(queries.begin(), queries.end());
    int l = 1, r = 1;
    cnt[a[1]]++;
    ll res = 0;
    res += a[1];
    for(auto c : queries){
        while(r < c.r){
            r++;
            res -= 1LL*cnt[a[r]]*cnt[a[r]]*a[r];
            cnt[a[r]]++;
            res += 1LL*cnt[a[r]]*cnt[a[r]]*a[r];
        }
        while(l > c.l){
            l--;
            res -= 1LL*cnt[a[l]]*cnt[a[l]]*a[l];
            cnt[a[l]]++;
            res += 1LL*cnt[a[l]]*cnt[a[l]]*a[l];
        }
        while(l < c.l){
            res -= 1LL*cnt[a[l]]*cnt[a[l]]*a[l];
            cnt[a[l]]--;
            res += 1LL*cnt[a[l]]*cnt[a[l]]*a[l];
            l++;
        }
        while(r > c.r){
            res -= 1LL*cnt[a[r]]*cnt[a[r]]*a[r];
            cnt[a[r]]--;
            res += 1LL*cnt[a[r]]*cnt[a[r]]*a[r];
            r--;
        }
        sol[c.ind] = res;
    }
    for(int i=1; i<=t; i++) cout << sol[i] << "\n";
    return 0;
}