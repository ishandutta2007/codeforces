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
    int t; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        int r,c; cin >> r >> c,--r,--c;
        vector<string> g(n);
        int bs=0;
        for(auto& i : g) cin >> i,bs+=count(all(i),'B');
        if(!bs) cout << "-1\n";
        else if(g[r][c]=='B') {
            cout << "0\n";
        } else {
            bool good=false;
            for(int i=0;i<n;++i) {
                if(g[i][c]=='B') good=true;
            }
            for(int i=0;i<m;++i) {
                if(g[r][i]=='B') good=true;
            }
            cout << 1+!good << '\n';
        }

    }
}