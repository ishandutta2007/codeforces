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
string ans;
bool visited[mxN];
int sz[mxN];
void dfsz(int at, int from) {
    sz[at] = 1;
    for(int to:adj[at]) {
        if(!visited[to] and to !=from) {
            dfsz(to,at);
            sz[at]+=sz[to];
        }
    }

}
int centroid(int at) {
    int total = sz[at], from = -1;
    bool done = false;
    while(!done) {
        done = true;
        for(int to: adj[at]) if(from!=to and !visited[to]) {
            if(sz[to]*2>total) {
                done = false;
                from = at;
                at = to;
                break;
            }
        }
    }
    return at;
}
void decomp(int at=0,char rank='A') {
    dfsz(at,-1);
    int c = centroid(at);
    visited[c] = true;
    ans[c]=rank;
    for(int to: adj[c]) {
        if(!visited[to]) decomp(to,rank+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    ans = string(n,'?');
    for(int i=0;i<n-1;++i) {
        int a,b;  cin >> a >> b,--a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    decomp();
    for(char c: ans) cout << c << ' ';
}