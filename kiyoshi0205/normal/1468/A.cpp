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
        int n; cin >> n;
        vector<int> a(n); rep(i,n) cin >> a[i], a[i]--;
        set<int> se;
        rep(i,n) se.insert(i);
        Segtree<ll> dp0(n,[](ll a, ll b){return max(a,b);},-inf); //min
        Segtree<ll> dp1(n,[](ll a, ll b){return max(a,b);},-inf); //
        dp0.update(0,0);
        rep(i,n){
            int qu0 = dp0.query(0,a[i]+1);
            int qu1 = dp1.query(0,a[i]+1);
            dp0.update(a[i],max(qu0,qu1)+1);
            while(!se.empty()){
                int tmp = *se.begin();
                if(tmp >= a[i]) break;
                dp1.update(tmp,dp0[tmp]+1);
                se.erase(se.begin());
            }
            se.insert(a[i]);
        }
        cout << max(dp0.query(0,n), dp1.query(0,n)) << "\n";
    }
}