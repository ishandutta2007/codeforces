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
const int mxN = 51+1;
const ll oo = 1e18;
struct bimatch {
    int n,m;
    vi mate;
    vector<bool> vis;
    vvi adj;
    bimatch(int nn,int mm) : n(nn),m(mm), mate(m,-1),vis(nn),adj(nn) {}
    void addE(int u,int v) {
        adj[u].push_back(v);
    }
    bool dfs(int at) {
        vis[at]=true;
        for(auto to : adj[at]) {
            if(mate[to]==-1) {
                mate[to]=at;
                return true;
            } else if(!vis[mate[to]] and dfs(mate[to])) {
                mate[to]=at;
                return true;
            }
        }
        return false;
    }
    int run() {
        int ans=0;
        for(int i=0;i<n;++i) {
            fill(all(vis),false);
            if(dfs(i)) ans++;
        }
        return ans;
    }
    vi order() {
        int maxM = run();
        vector<bool> used(n),removed(n);
        for(auto& i : mate) if(i!=-1) used[i]=true;
        vi res;
        while(maxM--) {
            fill(all(vis),false);
            for(int i=0;i<n;++i) if(!used[i]) 
                dfs(i);
            bool found=false;
            for(int i=0;i<n and !found;++i) if(used[i] and vis[i]) {
                found=true;
                used[i]=false;
                for(int j=0;j<m;++j) if(mate[j]==i) {
                    res.push_back(-j-1);
                    mate[j]=-1;
                    for(auto& v : adj) {
                        auto it = find(all(v),j);
                        if(it!=v.end()) v.erase(it);
                    }
                    break;
                }
            }
            for(int j=0;j<m and !found;++j) if(mate[j]!=-1) {
                int i = mate[j];
                res.push_back(i+1);
                used[i]=0;
                adj[i].clear();
                mate[j]=-1;
                found=true;
                break;
            }
            assert(found);
            
        }
        return res;
    }
};
int from[mxN][mxN];
int main() {
    // can always remove 1, just with a for loop
    int n,m,k; cin >> n >> m >> k;
    bimatch bm(n,n);
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v;
        bm.addE(u-1,v-1);
    }
    auto removals = bm.order();
    int maxM = removals.size();
    assert(removals.size()==maxM);
    vector<ll> dp(maxM+1,-oo);
    dp[maxM]=0;
    for(int i=1;i<=k;++i) {
        ll x,y; cin >> x >> y;
        vector<ll> ndp(maxM+1,-oo);
        for(int at=0;at<=maxM;++at) if(dp[at]!=-oo) {
            for(int to=min(n-i-1,at);to>=0;--to) {
                auto tmp = dp[at]+max(x-y*(at-to),0LL);
                if(tmp>ndp[to]) {
                    ndp[to]=tmp;
                    from[i][to]=at;
                }

            }
        }
        swap(dp,ndp);
    }
    int at = min(maxM,n-k-1),now=maxM;
    debug(dp[at]);
    cout << (maxM-at)+k << '\n';
    vi path = {at};
    for(int i=k;i>=1;--i) {
        at = from[i][at];
        path.push_back(at);
    }
    path.pop_back();
    reverse(all(path));
    auto it = removals.begin();
    assert(path.size()==k);
    for(int i : path) {
        while(now>i) {
            cout << *(it++) << ' ';
            now--;
        }
        cout << "0 ";
    }
    cout << '\n';



}