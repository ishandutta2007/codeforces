#pragma GCC optimize "Ofast"
#include "bits/stdc++.h"
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1;
const ll oo = 1e18;
struct el {
    int at;
    ll d;
    bool mn, mx;
    bool operator>(const el& o) const {
        return d > o.d;
    }
};
ostream& operator<<(ostream& c,const el& e) {
    return c << e.at << ' ' << e.d;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n>> m;
    vector<vector<pi>> adj(n);
    for(int i=0;i<m;++i) {
        int a,b,c; cin >> a >> b >> c;
        --a,--b;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    typedef __gnu_pbds::priority_queue<el,greater<el>,__gnu_pbds::thin_heap_tag> fastpriority_queue;
    fastpriority_queue pq;
    pq.push({0,0,0,0});
    vector<ll> dist(4*n,oo); dist[0] = 0;
    vector<fastpriority_queue::point_iterator> lookup(4*n);
    auto id = [n](int to, bool a, bool b) {
        return to+n*(a+2*b);
    };
    while(!pq.empty()) {
        auto c = pq.top();
        // debug(c); 
        pq.pop();
        if(dist[c.at] < c.d) {
            continue;
        }
        int rat = c.at%n;
        for(auto [to,w] : adj[rat]) {
            ll nd = c.d+ w;
            for(int i=c.mn; i <2;++i) {
                for(int j=c.mx;j<2;++j) {
                    int nto = id(to,i,j);
                    ll nnd = nd+w*((c.mx!=j)-(c.mn!=i));
                    if(nnd < dist[nto]) {
                        el e = {nto,nnd,i,j};
                        if(dist[nto]!=oo) {
                            pq.modify(lookup[nto], e);
                        } else {
                            lookup[nto] = pq.push(e);
                        }
                        dist[nto] = nnd;
                        
                    }
                }
            }
        }
    }
    for(int i=1+n*3;i<4*n;++i) {
        cout <<  dist[i] << ' ';
    } cout << endl;

}