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
const int mxN = 3e5+1, oo = 1e9, LG=19;
int gotfirst[mxN][LG];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    vi a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    // lastgood
    int last[LG];
    for(int i=0;i<LG;++i) last[i] = n;
    for(int i=n-1;i>=0;--i) {
        for(int j=0;j<LG;++j) {
            gotfirst[i][j] = n;
        }
        for(int j=0;j<LG;++j) {
            if(1<<j & a[i]) {
                gotfirst[i][j] = i;
                if(last[j]!=n) for(int to=0;to<LG;++to) {
                    gotfirst[i][to] = min(gotfirst[i][to],gotfirst[last[j]][to]);
                }
                last[j] = i;
            }
        }
    }

    while(q--) {
        int x,y; cin >> x >> y,--x,--y;
        bool found = false;
        for(int i=0;i<LG;++i) {
            if((a[y]&(1<<i)) and gotfirst[x][i]<=y) {
                found = true;
                break;
            }
        }
        cout << (found?"Shi\n":"Fou\n");
        

    }
}