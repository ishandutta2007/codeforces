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
vector<array<int,3>> bfs(int state, int n, bool allowed=false) {
        // do BFS
    queue<int> q;
    vi par(1<<n,0);
    par[state]=-1;
    q.push(state);
    vector<array<int,3>> ops;
    int MSK = (1<<n)-1;
    while(!q.empty()) {
        auto at = q.front(); q.pop();
        if(at==0) {
            while(at!=state) {
                int p = par[at];
                int change = p^at;
                vi bits;
                for(int i=0;i<n;++i) if((1<<i)&change) bits.push_back(i);
                if(bits.size()==1) bits.push_back(n);
                if(bits.size()==2) bits.push_back(bits[1]+(bits[1]-bits[0]));
                ops.push_back({bits[0],bits[1],bits[2]});
                at=p;
            }
            break;
        }
        for(int i=0;i<n;++i) for(int j=i+1;j<=n;++j) {
            int k = j+(j-i);
            int mask = (1<<i)|(1<<j)|(1<<k);
            mask&=MSK;
            if(allowed or k<n) {
                auto to = at^mask;
                if(!par[to]) {
                    par[to] = at;
                    q.push(to);
                }
            }
        }
    }
    if(par[0]==0) {
        cout << "NO\n";
        exit(0);
    }
    return ops;
}
int main() {
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    vector<array<int,3>> ops;
    auto doOp = [&](int x,int y, int z) {
        ops.push_back({x,y,z});
        a[x]^=1,a[y]^=1,a[z]^=1;
    };
    array<vector<array<int,3>>,(int) (1<<6)> need = {};
    for(int i=0;i<(1<<6);++i) {
        need[i] = bfs(i,6,true);
        assert(need[i].size()<=2);
    }
    while(a.size()>13) {
        int state=0,k =a.size()-1;
        for(int i=0;i<6;++i) {
            state|= a[k-i]<<i;
        }
        for(auto [x,y,z] : need[state]) {
            doOp(k-z,k-y,k-x);
        }
        for(int i=0;i<6;++i) a.pop_back();

    }
    n = a.size();
    int state=0;
    for(int i=0;i<a.size();++i) state|=(a[i]<<i);
    auto v = bfs(state,n);
    for(auto i : v) ops.push_back(i);
    cout << "YES\n";
    cout << ops.size() << '\n';
    for(auto& i : ops) {
        for(auto& j : i) j++;
        cout << i << '\n';
    }
}