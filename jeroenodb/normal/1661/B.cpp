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
    const int S = 32768;
    array<int,S> ans;
    fill(all(ans),oo);
    ans[0]=0;
    vvi adj(S);
    for(int i=0;i<S;++i) {
        adj[(i*2)%S].push_back(i);
        adj[(i+1)%S].push_back(i);
    }
    vi q = {0};
    for(int i=0;i<q.size();++i) {
        auto at = q[i];
        for(auto to : adj[at]) {
            if(ans[to]==oo) ans[to]=ans[at]+1,q.push_back(to);
        }
    }
    int n; cin >> n;
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        cout << ans[a] << ' ';
    }
}