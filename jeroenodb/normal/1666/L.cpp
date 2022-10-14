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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    int s; cin >> s;
    vvi adj(n+1);
    for(int i=0;i<m;++i) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
    }
    vi mark(n+1), par(n+1);
    auto reconstruct = [&](int a,int b) {
        vi pa,pb;
        while(a!=s) {
            pa.push_back(a);
            a=par[a];
        }
        pa.push_back(s);
        reverse(all(pa));
        pa.push_back(b);
        while(b!=s) {
            pb.push_back(b);
            b=par[b];
        }
        pb.push_back(s);
        reverse(all(pb));
        cout << "Possible\n";
        for(auto p : {pa,pb}) cout << p.size() << '\n' << p << '\n';
        exit(0);
    };
    for(int st : adj[s]) {
        
        // do BFS
        vi q;
        auto process = [&](int to, int at) {
            if(to==s) return;
            if(mark[to]) {
                if(mark[to]!=st) {
                    reconstruct(at,to);
                }
            } else {
                par[to]=at;
                mark[to]=st;
                q.push_back(to);
            }
        };

        process(st,s);
        for(int i=0;i<q.size();++i) {
            int at = q[i];
            for(auto to : adj[at]) process(to,at);
        }
    }
    cout << "Impossible\n";
}