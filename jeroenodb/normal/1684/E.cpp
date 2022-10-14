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
void solve() {
    int n,k; cin >> n >> k;
    vector<pi> a;
    {
    map<int,int> aa; 
    for(int i=0;i<n;++i) {
        int v; cin >> v;
        aa[v]++;
    }
    a = vector<pi>(all(aa));
    }
    n = a.size();
    vi ord(n); iota(all(ord),0);
    sort(all(ord),[&](int i, int j) {return a[i].second<a[j].second;});
    vi rnk(n);
    for(int i=0;i<n;++i) rnk[ord[i]]=i;

    int have=0;
    int j=0;
    fenwick<int> f1(n),f2(n);
    for(int i=0;i<n;++i) {
        f2.update(i,a[ord[i]].second);
        f1.update(i,1);
    }
    int mid=-1;
    auto fix = [&]() {
        while(mid+1<n and f2.query(0,mid+1)<=k) {
            ++mid;
        }
        while(mid>=0 and f2.query(0,mid)>k) {
            --mid;
        }
    };
    fix();
    int ans = oo;
    for(int mex=0;;++mex) {
        int need = mex-have;
        if(need>k) break;
        int big = f1.query(0,mid);
        if(mex==0) ans=min(ans,max(1,n-big));
        else ans = min(ans,n-j-big);
        // big are groups, bunch of groups, need to find first of the group that is bad. 
        // sort groups based on size, find first group that can't be removed.
        while(j<n and a[j].first<=mex) {
            have++;
            // update data structure
            // delete a it->second from the data structure
            f1.update(rnk[j],-1);
            f2.update(rnk[j],-a[j].second);
            ++j;
        }
        fix();
    }

    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}