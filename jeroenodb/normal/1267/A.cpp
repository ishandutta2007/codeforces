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
typedef pair<ll,ll> pl;
const int mxN = 1e5+1;
const ll oo = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    struct event {
        ll x,t;
        bool operator<(const event& o) {return x<o.x or (x==o.x and t>o.t);}
    };
    vector<event> es(2*n);
    for(int i=0;i<2*n;i+=2) {
        ll a,b,t; cin >> a >> b >> t;
        es[i] = {a,t};
        es[i+1] = {b-t,-t};
    };
    ll ans=0;
    sort(all(es));
    es.push_back({oo,oo});
    multiset<ll> best;
    ll tstop=-oo, nxtplace=oo;
    for(auto& e : es) {
        if(nxtplace<=e.x) {
            ans++;
            tstop=nxtplace;
            if(!best.empty()) {
                auto shortest = *best.begin();
                ll dur=e.x-tstop;
                ll used = dur/shortest;
                ans+=used;
                tstop+=used*shortest;
                nxtplace = tstop+shortest;
            } else tstop=e.t,nxtplace=oo;
        } 
        if(e.t>0) nxtplace = min(nxtplace,e.x+e.t);
        if(e.t>0) {
            best.insert(e.t);
        } else best.erase(best.find(-e.t));
        
    }
    cout << ans << '\n';
}