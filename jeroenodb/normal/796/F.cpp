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
const int mxN = 1e5+1, oo = 1e9+1;
void cmin(int& a, int b) {a=min(a,b);}
struct segtree {
    int ptwo;
    vector<int> seg;
    segtree(){}
    int& operator[](int i) {
        return seg[i+ptwo];
    }
    segtree(int nn, int val) {
        ptwo=1;
        while(ptwo<nn) 
            ptwo*=2;
        seg.assign(ptwo*2,val);
    }
    auto query(int l, int r) {
        assert(l>=0 and l<ptwo and r >=0 and r<ptwo);
        l+=ptwo; r+=ptwo;
        int res = -oo;
        while(l and l<=r) {
            if(l%2==1) res = max(res,seg[l++]);
            if(r%2==0) res = max(res,seg[r--]);
            l/=2; r/=2;
        }
        return res;
    }
    void set(int l, int r, int x) {
        l+=ptwo; r+=ptwo;
        while(l and l<=r) {
            if(l%2==1) cmin(seg[l++],x);
            if(r%2==0) cmin(seg[r--],x);
            l/=2; r/=2;
        }
    };
    auto querySingle(int i) {
        int ans = oo;
        for(i+=ptwo;i>=1;i/=2) {
            cmin(ans,seg[i]);
        }
        return ans;
    }
    void update(int i, int val) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        seg[i] = val;
        for(i/=2;i>=1;i/=2) {
            seg[i] = max(seg[2*i],seg[2*i+1]);
        }
    }
};
void impos() {
    cout << "NO\n";
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    
    struct op {
        int t,l,r,x;
        // bool useful=true;
    };
    vector<op> ops(m);
    for(auto& o : ops) {
        cin >> o.t;
        if(o.t==1) cin >> o.l >> o.r >> o.x,--o.l,--o.r;
        else if(o.t==2) cin >> o.l >> o.x,--o.l;
    }
    vector<bool> alive(n,1);
    vi a(n,-1);
    {
        segtree seg(n,0), seg2(n,oo);
        for(auto& o : ops) {
            if(o.t==1) {
                auto tmp  =seg.query(o.l,o.r);
                seg2.set(o.l,o.r,o.x);
                if(o.x<tmp) impos();
            } else {
                if(alive[o.l]) {
                    a[o.l] = seg2.querySingle(o.l);
                    alive[o.l]=0;
                }
                seg.update(o.l,o.x);
            }
        }
        for(int i=0;i<n;++i) if(alive[i]) a[i] = seg2.querySingle(i);
    }
    // ops.erase(stable_partition(all(ops),[&](auto i) {return i.useful;}),ops.end());

    // check array
    auto b = a;
    segtree seg(n,0);
    for(int i=0;i<n;++i) seg.update(i,b[i]);
    for(auto& o : ops) {
        if(o.t==1) {
            if(seg.query(o.l,o.r)!=o.x) impos();
        } else {
            seg.update(o.l,o.x);
        }
    }
    vi free;
    set<int> have;
    int ans=0;
    for(int i=0;i<n;++i) {
        if(a[i]==oo) free.push_back(i);
        else if(have.count(a[i])) free.push_back(i);
        else {
            have.insert(a[i]);
            ans|=a[i];
        }
    }
    int best = (1<<30)-1;
    for(auto& i : free) {
        int need = ans^best;
        int limit = a[i];
        if(limit==oo) limit--;
        a[i] = 0;
        for(int j=29;j>=0;--j) {
            if(a[i]+(1<<j) <= limit and need&(1<<j)) {
                a[i]|=1<<j;
            }
        }
        ans|=a[i];
    }
    cout << "YES\n";
    cout << a << '\n';


}