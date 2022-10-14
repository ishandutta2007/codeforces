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
const int mxN = 500+4, oo = 1e9;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
struct bimatching {
    int n,m;
    vector<bool> vis;
    vvi adj;
    vi match;
    bimatching(int x, int y) : n(x),m(y),vis(x),adj(x),match(y,-1) {}
    bool dfs(int at) {
        vis[at]=true;
        for(auto to : adj[at]) {
            int& o = match[to];
            if(o==-1 or (!vis[o] and dfs(o))) {
                o=at;
                return true;
            }
        }
        return false;
    }
    int run() {
        for(auto& v : adj) shuffle(all(v),rng);
        int ans=0;
        vector<bool> used(n);
        for(int i=0;i<n;++i) {
            for(auto to : adj[i]) if(match[to]==-1) {
                match[to]=i;
                used[i]=true;
                ans++;
                break;
            }
        }
        
        for(int i=0;i<n;++i) if(!used[i]) {
            fill(all(vis),0);
            ans+=dfs(i);
        }
        return ans;
    }
};
bool a[mxN][mxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    int total=0;
    vector<string> s(n);
    for(auto& i : s) {
        cin >> i,i+='W';
        for(auto& j : i) {
            j=(j=='B');
        }
    }
    s.push_back(string(m+1,0));
    for(int i=0;i<n;++i)for(int j=0;j<m;++j) {
        a[i][j] = (s[i][j]^s[i+1][j]^s[i][j+1]^s[i+1][j+1]);
        total+=a[i][j];
    }
    bimatching bm(n-1,m-1);
    for(int i=0;i<n-1;++i) for(int j=0;j<m-1;++j) {
        if(a[i][j] and a[i][m-1] and a[n-1][j]) {
            bm.adj[i].push_back(j);
        }
    }
    int k =bm.run();
    int ans = oo;
    for(int i=0;i<=k;++i) {
        int saveOne = 0;
        if(a[n-1][m-1] and (i&1)) saveOne=1;
        else if(!a[n-1][m-1] and (i&1)) saveOne=-1;
        ans=min(ans,total-saveOne-i);
    }
    cout << ans  << '\n';
}