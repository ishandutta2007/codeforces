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
const int mxN = 2e3+1, oo = 1e9;
typedef bitset<mxN> vec;
typedef char F;
valarray<F> gaussianElim(vector<valarray<F>>& A, int cols) {
    int at= 0;
    vi ids;
    for(int i=0;i<cols and at<A.size();++i) {
        for(int j=at;j<A.size();++j) if(A[j][i]) {
            swap(A[j],A[at]);
            break;
        }
        if(A[at][i]==0) continue;
        ids.push_back(i);
        for(int j=0;j<A.size();++j) if(A[j][i]!=0 and j!=at) {
            A[j]^=A[at];
        }
        // for(auto& j : A) {
        //     debug(j);
        // }
        // cout << endl;
        ++at;
    }
    valarray<F> res(cols+1);
    for(int i=ids.size()-1;i>=0;--i) {
        res[ids[i]] = ((A[i] & res).sum()%2) ^ A[i][cols];
    }
    return res;
}
void solve() {
    int n,m; cin >> n >> m;
    vector<valarray<F>> v;
    vector<valarray<F>> adj(n, valarray<F>(n+1));
    while(m--) {
        int u,v; cin >> u >> v,--u,--v;
        adj[u][v]=true;
        adj[v][u]=true;
    }
    bool got = false;
    for(int i=0;i<n;++i) {
        if(adj[i].sum()%2==0) {
            v.push_back(adj[i]);
        } else {
            got=true;
            adj[i][i]=true;
            adj[i][n]=true;
            v.push_back(adj[i]);
        }
    }
    if(!got) v = {};
    auto res = gaussianElim(v,n);
    cout << res.max()+1 << ' ';
    for(int i=0;i<n;++i) {
        cout << res[i]+1 << ' ';
    }
    cout << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}