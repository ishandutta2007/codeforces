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
bitset<mxN> vis;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        vis[a]=true;
    }
    for(int i=mxN-1;i>0;--i) {
        int g=0;
        for(int j=i*2;j<mxN;j+=i) if(vis[j]) {
            g = gcd(g,j);
        }
        if(g==i) vis[i]=true;
    }
    cout << vis.count()-n << '\n';
}