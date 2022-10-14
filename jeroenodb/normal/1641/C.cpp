#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
struct segtree {
    int ptwo;
    vector<int> seg;
    segtree(){}
    int& operator[](int i) {
        return seg[i+ptwo];
    }
    segtree(int nn) {
        ptwo=1;
        while(ptwo<nn) 
            ptwo*=2;
        seg.assign(ptwo*2,oo);
    }
    auto query(int l, int r) {
        assert(l>=0 and l<ptwo and r >=0 and r<ptwo);
        l+=ptwo; r+=ptwo;
        int res = oo;
        while(l and l<=r) {
            if(l%2==1) res = min(res,seg[l++]);
            if(r%2==0) res = min(res,seg[r--]);
            l/=2; r/=2;
        }
        return res;
    }
    void update(int i, int val) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        seg[i] = min(seg[i],val);
        for(i/=2;i>=1;i/=2) {
            seg[i] = min(seg[2*i],seg[2*i+1]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    set<int> ones;
    for(int i=-1;i<=n+1;++i) ones.insert(i);
    segtree seg(n);
    vector<bool> bad(n+2);
    while(q--) {
        int t; cin >> t;
        if(t==1) {
            int x; cin >> x,--x;
            if(ones.count(x)) {
                if(bad[x]) cout << "YES\n";
                else cout << "N/A\n";
            } else cout << "NO\n";
        } else {
            int l,r,x; cin >> l >> r >> x;
            --l,--r;
            if(x==1) {
                seg.update(l,r);
                auto it = ones.lower_bound(l);
                if(*next(it)>r) {
                    bad[*it]=true;
                }
            } else {
                for(auto it = ones.lower_bound(l);*it<=r;) {
                    it = ones.erase(it);
                }
                auto check = [&](auto it) {
                    if(*it<0 or *it>=n) return;
                    if(seg.query(*prev(it)+1, *it) < *next(it)) {
                        bad[*it]=true;
                    }
                };
                auto it = ones.lower_bound(l);
                check(it), check(prev(it));
            }
        }
    }
}