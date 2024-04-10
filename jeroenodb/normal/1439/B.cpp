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
vi adj[mxN];
int deg[mxN];
struct bloomfilter {
    int sz;
    vector<bool> bs;
    bloomfilter(int m) {
        sz = m*10+2001;
        bs.resize(sz);
    }
    bool count(const pi& p) {
        auto h1 = (123ULL+p.first*39ULL^p.second)%sz;
        auto h2 = (1234ULL+p.first*3ULL+45ULL*p.second)%sz;
        return bs[h1] and bs[h2];
    }
    auto insert(const pi& p) {
        auto h1 = (123ULL+p.first*39ULL^p.second)%sz;
        auto h2 = (1234ULL+p.first*3ULL+45ULL*p.second)%sz;
        bs[h1]=true;
        bs[h2]=true;
    }
};
void solve() {
    int n,m,k; cin >> n >> m >> k;
    for(int i=0;i<n;++i) adj[i].clear(),deg[i]=0;
    bloomfilter es(m);
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v,--u,--v;
        if(u>v) swap(u,v);
        es.insert({u,v});
        adj[u].push_back(v),adj[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    queue<int> nope;
    vector<bool> good(n,true);
    for(int i=0;i<n;++i) if(deg[i]<k) {
        nope.push(i),good[i]=false;
    }
    while(!nope.empty()) {
        int at = nope.front(); nope.pop();
        for(int to: adj[at]) {
            if(--deg[to]==k-1) {
                nope.push(to);
                good[to]=false;
            }
        }
    }
    int sz = count(all(good),true);
    if(sz) {
        cout << "1 " <<  sz << '\n';
        for(int i=0;i<n;++i) if(good[i]) {
            cout << i+1 << ' ';
        } cout << '\n';
    } else {
        if(k*(k-1)/2<=m) {
            if(k==1) {
                cout << "2\n1\n";
                return;
            }
            for(int i=0;i<n;++i) deg[i] = adj[i].size();
            good.assign(n,true);
            queue<int> special;
            for(int i=0;i<n;++i) {
                if(deg[i]<k-1) {
                    nope.push(i),good[i]=false;
                } else if(deg[i]==k-1) special.push(i);
            }

            auto clean = [&]() {
                while(!nope.empty()) {
                    int at = nope.front(); nope.pop();
                    for(int to: adj[at]) {
                        if(--deg[to]==k-2) {
                            nope.push(to),good[to]=false;
                        }
                        if(deg[to]==k-1) special.push(to);
                    }
                }
            };
            clean();
            auto check = [&](int at) {
                vi before;
                for(int to : adj[at]) if(good[to]) {
                    for(int i : before) {
                        pi want = {i,to};
                        if(want.first>want.second) swap(want.first,want.second);
                        if(!es.count(want)) return vi{};
                    }
                    before.push_back(to);
                }
                return before;
            };
            while(!special.empty()) {
                int at = special.front();
                special.pop();
                if(deg[at]!=k-1) continue;
                auto v = check(at);
                if(!v.empty()) {
                    v.push_back(at);
                    cout << "2\n";
                    for(int i : v) cout << i+1 << ' ';
                    cout << '\n';
                    return;
                }
                good[at]=false;
                deg[at]=0;
                nope.push(at);
                clean();
            }
            cout << "-1\n";
        } else {
            cout << "-1\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}