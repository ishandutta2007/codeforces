// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
struct DS {
    typedef array<ll,3001> DP;
    DS() {
        st.push_back({});
        fill(all(st.back()),(ll)-1e18);
        st.back()[0]=0;
    }
    vector<DP> st;
    vi check;
    ll query(int k) {
        return st.back()[k];
    }
    void add(int w, ll c) {
        DP nw = st.back();
        for(int i=w;i<3001;++i) nw[i]=max(nw[i],st.back()[i-w]+c);
        st.push_back(nw);
    } 
    void addC() {check.push_back(st.size());}
    void undo() {
        while(check.back()<(int)st.size()) st.pop_back();
        check.pop_back();
    }
} ds;
struct Upd {
    int l, r;
    int w; ll c;
};
ll ans = 0;
vvi a;
int k;
void solve(int l, int r, vector<Upd>& es) {
    ds.addC();
    auto it  = partition(all(es),[&](const auto& e) {return !(e.l<=l and r<=e.r);});
    for(auto i = it;i!=es.end();++i) {
        auto& e = *i;
        ds.add(e.w,e.c);
    }
    es.erase(it,es.end());
    if(l+1==r) {
        // good
        auto& v = a[l];
        ll sm=0;
        ans = max(ans,ds.query(k));
        for(int i=0;i<(int)v.size();++i) {
            int o = k-i-1;
            sm+=v[i];
            ans = max(ds.query(o)+sm,ans);
        }
    } else {
        int mid = (l+r)/2;
        vector<Upd> el,er;
        for(const auto& e : es) {
            if(e.l<mid and e.r>l) {
                el.push_back(e);
            }
            if(e.l<r and e.r>mid) {
                er.push_back(e);
            }
        }
        solve(l,mid,el);
        solve(mid,r,er);
    }
    ds.undo();
}
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto t0 = std::chrono::steady_clock::now();
    int n; 
    cin >> n >> k;
    // n = 3000,k=3000;
    a.resize(n);
    for(auto& v : a) {
        int t; 
        cin >> t;
        // t = rnd(100,3000);
        v.resize(t);
        int lb=0;
        for(auto& i : v) {
            cin >> i;
            // i = rnd(lb,lb+100000);
            lb=i;
        }
        v.resize(min(t,k));
    }
    vector<Upd> updates;
    for(int i=0;i<n;++i) {
        ll sm = accumulate(all(a[i]),0LL);
        int w = a[i].size();
        if(i!=n-1) updates.push_back({i+1,n,w,sm});
        if(i) updates.push_back({0,i,w,sm});
    }
    solve(0,n,updates);
    cout << ans << '\n';
    cerr << (std::chrono::steady_clock::now()-t0).count() * 1e-9 << endl;
}