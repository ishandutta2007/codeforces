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
const int mxN = 2.5e5+1, oo = 1e9;
template<typename T> struct fenwick {
    int n;
    vector<T> fen;
    fenwick(){}
    fenwick(int nn) {
        fen.resize(nn+1);
        n = nn;
    }
    auto sum(int i) {
        T ans = 0;
        while(i) {
            ans+=fen[i];
            i&=i-1;
        }
        return ans;
    }
    auto query(int l, int r) {
        return sum(r+1)-sum(l);
    }
    void update(int i, T val) {
        ++i;
        while(i<=n) {
            fen[i]+=val;
            i+= i&(-i);
        }
    }
};
template<int N> struct pt {
    int x[N]={};
    bool see = true,vis=true;
    int id=-oo;
    bool operator<(const pt& o) const {
        return x[0]<o.x[0] or (x[0]==o.x[0] and see>o.see);
    }
};
int ans[mxN];
fenwick<int> fen(mxN);
vi updates;
void base(vector<pt<2>>& pts) {
    for(auto& i : pts) {
        int y = i.x[1];
        if(i.vis) ans[i.id]+=fen.query(0,y);
        if(i.see) {
            updates.push_back(y);
            fen.update(y,1);
        }
    }
    for(auto i : updates) fen.update(i,-1);
    updates.clear();
}
template<int N> void solve(vector<pt<N>>& pts, int l, int r) {
    if(l==r-1) return;
    if constexpr (N==2) {
        base(pts);
    } else {
        auto mid = (l+r)/2;
        solve(pts, l,mid),solve(pts, mid,r);
        vector<pt<N-1>> lo; 
        for(int k=l;k<r;++k) {
            auto& q = pts[k];
            pt<N-1> p;
            p.id = q.id;
            for(int j=1;j<N;++j) {
                p.x[j-1] = q.x[j];
            }
            p.see = k<mid, p.vis = !p.see;
            if(k<mid?q.see:q.vis) 
                lo.push_back(p);
        }
        sort(all(lo));
        solve(lo,0,lo.size());
    }
}

int n,m;
void init() {
    cin >> n >> m;
    vector<pt<3>> pts(n+m);
    vi p(n), s(n),b(n),inc(m),pref(m);
    
    auto rd = [&](vi& a) {for(auto& i : a) cin >> i;};
    rd(p),rd(s),rd(b),rd(inc),rd(pref);
    vi coord; coord.reserve(n+m);
    for(auto& i : s) coord.push_back(-i);
    for(auto& i : inc) coord.push_back(-i);
    sort(all(coord));
    coord.erase(unique(all(coord)),coord.end());
    auto cc = [&](const vi& a) {
        vi res;
        for(auto& i: a) res.push_back(lower_bound(all(coord),-i)-coord.begin());
        return res;
    };
    auto lcs = cc(s), lcinc = cc(inc);
    for(int i=0;i<n;++i) {
        pts[i] = pt<3>{{b[i]+p[i],p[i]-b[i],lcs[i]},true,false,-oo};
    }
    for(int i=0;i<m;++i) {
        pts[i+n] = pt<3>{{inc[i]+pref[i],inc[i]-pref[i],lcinc[i]},false,true,i};
    }
    sort(all(pts));
    solve(pts,0,n+m);
    for(int i=0;i<m;++i) {
        cout << ans[i] << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
}