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
const int mxN = 1e5+1, oo = 1e9, M = 1<<22;
bitset<M*2> vis;
bitset<M> have;
int n;
void bfs(int s) {
    vi q;
    auto process = [&](int i) {
        if(vis[i]) return;
        vis[i]=true;
        q.push_back(i);
    };
    process(s);
    for(int i=0;i<(int)q.size();++i) {
        int at = q[i];
        if(at>=M) {
            at-=M;
            for(int j=0;j<n;++j) {
                process( (at&(~(1<<j)))+M);
            }
            if(have[at]) process(at);
        } else {
            process( (((1<<n) - 1)^at) + M);
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m; cin >> n >> m;
    for(int i=0;i<m;++i) {
        int a; cin >> a;
        have[a]=true;
    }
    int ans=0;
    for(int i=0;i<1<<n;++i) if(have[i] and !vis[i]) {
        // bfs
        ans++;
        bfs(i);
    }
    cout << ans << '\n';
}