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
struct group {
    int id;
    ll sm=0;
    int k;
    vi st;
    void read() {
        cin >> k;
        st.resize(k);
        for(auto& i : st) {
            cin >> i;
            sm+=i;
        }
    }
    bool operator<(const group& o) const {
        return sm*o.k< o.sm*k;
    }
};
void solve() {
    int n,m; cin >> n >> m;
    vector<ll> a(n);
    for(auto& i : a) cin >> i;
    sort(all(a));
    a.erase(a.begin(),a.begin()+n-m);
    // more teachers than needed
    vector<group> gs(m);
    int total=0;
    for(auto& i : gs){
        i.read();
        i.id=total;
        total+=i.k;
    } 
    
    sort(all(gs));

    vi bad(m+1), badl(m+1), badr(m+1);
    for(int i=0;i<m;++i) {
        bad[i+1] = bad[i]+ (gs[i].sm > a[i]*gs[i].k);
        badl[i+1]=badl[i], badr[i+1]=badr[i];
        if(i) badl[i+1]+= (gs[i].sm > a[i-1]*gs[i].k);
        if(i!=m-1) badr[i+1]+= (gs[i].sm > a[i+1]*gs[i].k);
    }
    string res(total,'?');
    for(int i=0;i<m;++i) {
        auto& g = gs[i];
        for(auto j : g.st) {
            group ng;
            ng.k=g.k-1;
            ng.sm = g.sm-j;
            int split = lower_bound(gs.begin(),gs.begin()+i,ng)-gs.begin();
            if(split==i) {
                split = lower_bound(gs.begin()+i+1,gs.end(),ng)-gs.begin();
            }
            bool bd = false;
            if(split<=i) {
                bd|= ng.sm > a[split]*ng.k;
                bd|= badr[i]-badr[split]>0;
                bd|= bad[split]>0;
                bd|= bad[m]-bad[i+1]>0;
            } else {
                bd|= ng.sm > a[split-1]*ng.k;
                bd|= badl[split]-badl[i+1]>0;
                bd|= bad[i]>0;
                bd|= bad[m]-bad[split]>0;
            }
            res[g.id] = (bd?'0':'1');
            g.id++;
        }
    }
    cout << res << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}