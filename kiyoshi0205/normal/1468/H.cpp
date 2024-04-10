#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(int i=0; i<(n); i++)

template<typename monoid>
struct Segtree{
    using F = function<monoid(monoid,monoid)>;
    int sz;
    vector<monoid> seg;
    const F f;
    const monoid M;

    Segtree(int n, const F f, const monoid &M) : f(f), M(M){
        sz = 1;
        while(sz < n) sz <<= 1;
        seg.assign(2*sz,M);
    }

    void update(int k, const monoid &x){
        k += sz;
        seg[k] = x;
        while(k >>= 1){
            seg[k] = f(seg[2*k], seg[2*k+1]);
        }
    }

    monoid query(int a, int b){
        monoid L = M, R = M;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1){
            if(a & 1) L = f(L,seg[a++]);
            if(b & 1) R = f(seg[--b],R);
        }
        return f(L,R);
    }

    monoid operator[](const int &k) const {
        return seg[k+sz];
    }
};

const int inf = (1<<30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int n,k,m; cin >> n >> k >> m;
        vector<int> b(m+1); rep(i,m) cin >> b[i+1];
        b[0] = 0; 
        if((n-m) % (k-1) != 0){
            cout << "NO" << "\n";
            continue;
        }
        int cnt = 0;
        int cnt2 = n-m;
        bool yes = false;
        for(int i=1; i<=m; i++){
            cnt += b[i] - b[i-1] - 1;
            cnt2 -= b[i] - b[i-1] - 1;
            if(cnt >= k/2 && cnt2 >= k/2) yes = true;
        }
        if(yes) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}