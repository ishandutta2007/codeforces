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
    vi a(n-1);
    for(auto& i : a) cin >> i,--i;
    int root = a[0];
    vector<bool> vis(n);
    vi par(n,-1);
    int search=n-1, last=-1;
    auto update = [&]() {
        while(search>=0 and (vis[search] or search==root)) --search;
    };
    update();
    for(auto i : a) {
        if(search==i or vis[i]) {
            par[search]=last;
            vis[search]=1;
            --search;
            update();
        }
        if(!vis[i]) {
            vis[i]=1;
            par[i]=last;
        }
        last=i;
    }
    if(search>=0) par[search]=last;
    cout << root+1 << '\n';
    for(int i=0;i<n;++i) if(root!=i) {
        cout << i+1 << ' ' << par[i]+1 << '\n';
    }

}