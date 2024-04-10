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
void cmax(ll& a, ll b) {a=max(a,b);}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a; cin >> n >> a;
    ll ans = 0;
    struct el {
        ll gap=2e18, best=-1e18, sm=0,total=-1e18;
    };
    vector<el> v = {{}};
    int pd=0;
    for(int i=0;i<n;++i) {
        int d,c; cin >> d >> c;
        ll gap = ll(d-pd)*(d-pd);
        el nw = {gap,ll(-1e18),0, (ll)-1e18};
        bool toadd=false;
        while(v.back().gap<gap) {
            toadd=true;
            cmax(nw.best, v.back().best+nw.sm);
            nw.sm+=v.back().sm;
            v.pop_back();
        }
        auto add = [&](el e) {
            cmax(e.total, max(e.best-e.gap, v.back().total+e.sm));
            v.push_back(e);
        };
        if(toadd) add(nw);
        int mysm = a-c;
        nw = {0,mysm,mysm,(ll)-1e18};
        add(nw);
        ans = max(ans,v.back().total);
        pd=d;
    }
    cout << ans << '\n';
}