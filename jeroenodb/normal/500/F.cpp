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
const int mxN = 3e4+1, CAP = 4000, oo = 1e9;
int p;
vi ans;
vi budget;
vi qids[mxN];
typedef array<int,CAP+1> DP;
vector<DP> dp = {{}};
struct el {
    int c,h,t;
    void read(){cin >> c >> h >> t;}
};
vector<el> els;
void update(DP& a,el& e) {
    for(int i=CAP-e.c;i>=0;--i) {
        a[i+e.c]=max(a[i+e.c],a[i]+e.h);
    }
}
void solve(int l, int r, const vi& got) {
    vi left;
    for(auto& ii : got) {
        auto& e = els[ii];
        if(e.t<=l and e.t+p>r) {
            update(dp.back(),e);
        } else if(e.t<=r or e.t+p>l) {
            left.push_back(ii);
        }
    }
    if(l==r) {
        for(auto qi : qids[l]) {
            ans[qi] = dp.back()[budget[qi]];
        }
        return;
    }
    dp.push_back(dp.back());
    int mid = (l+r)/2;
    solve(l,mid,left);
    dp.back() = dp.end()[-2];
    solve(mid+1,r,left);
    dp.pop_back();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n >> p;
    els.resize(n);
    for(auto& e : els) e.read();
    int q; cin >> q;
    ans.resize(q);
    budget.resize(q);
    int mn = oo,mx=-oo;
    for(int i=0;i<q;++i) {
        int t; cin >> t >> budget[i];
        mn = min(t,mn),mx = max(t,mx);
        qids[t].push_back(i);
    }
    vi elids(n); iota(all(elids),0);
    solve(mn,mx,elids);
    for(auto i : ans) cout << i << '\n';
}