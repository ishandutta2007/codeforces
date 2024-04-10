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
    int n; cin >> n;
    vi a(n), leaves(n);
    vector<ll> left(n),mx(n);
    vvi adj(n);
    for(int i=1;i<n;++i) {
        int parent;
        cin >> parent; parent--;
        adj[parent].push_back(i);
    }
    for(int& i: a) cin >> i;
    vector<int> order = {0};
    for(int i=0;i<n;++i) {
        int at = order[i];
        for(int to: adj[at]) {
            order.push_back(to);
        }
    }
    for(int i=n-1;i>=0;--i) {
        int at = order[i];
        if(adj[at].size()==0) {
            leaves[at]=1;
            mx[at]=a[at];
            continue;
        }
        for(int to: adj[at]) {
            leaves[at]+=leaves[to];
            mx[at] = max(mx[at],mx[to]);
            left[at]+=left[to];
        }
        for(int to:adj[at]) {
            left[at]+=(mx[at]-mx[to])*leaves[to];
        }
        left[at]-=a[at];
        if(left[at]<0) {
            ll delta = (leaves[at]-1-left[at])/leaves[at];
            mx[at]+=delta;
            left[at]+=delta*leaves[at];
        }
    }
    cout << mx[0] << endl;

    
}