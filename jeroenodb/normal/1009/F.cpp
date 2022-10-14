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
const int mxN = 1e6+1, oo = 1e9;
struct backwardsvec {
    vi v = {1};
    int& operator[](int i) {
        return v[v.size()-i-1];
    }
    void push_front(int vv) {
        v.push_back(vv);
    }
};
struct DS {
    int best=0;
    backwardsvec v;
    void insert(int d, int a) {
        v[d]+=a;
        if(make_pair(v[d],-d)>make_pair(v[best],-best)) {
            best = d;
        }
    }
    int size() {return v.v.size();}
    void shift() {
        v.push_front(0);
        best++;
    }
    int get(){
        return best;
    }
};
vi adj[mxN];
DS ds[mxN];
int ans[mxN];
void dfs(int at,int from) {
    for(auto to : adj[at]) if(to!=from) {
        dfs(to,at);
        ds[to].shift();
        if(ds[at].size()<ds[to].size()) swap(ds[at],ds[to]);
        for(int i=0;i<ds[to].size();++i) {
            ds[at].insert(i,ds[to].v[i]);
        }
    }
    ans[at]= ds[at].get();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<n;++i) {
        int a,b; cin >> a >> b;
        --a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0,0);
    for(int i=0;i<n;++i) cout << ans[i] << '\n';
}