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
int query(int i) {
    cout << "? " << i+1 << endl;
    cin >> i;
    return i-1;
}
void solve() {
    int n; cin >> n;
    vi p(n);
    vector<bool> vis(n);
    for(int j=0;j<n;++j) if(!vis[j]) {
        int at = query(j);
        vi st;
        while(!vis[at]) {
            vis[at]=true;
            st.push_back(at);
            at = query(j);
            
        }
        // now only find right rotation?
        // not even right rotation, just find j
        int k = st.size();
        for(int i=0;i<k;++i) {
            p[st[i]]=st[(i+1)%k];
        }
    }
    cout << "!";
    for(auto& i : p) {
        cout << ' ' << i+1;
    }
    cout << endl;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}