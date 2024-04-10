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
const int denum = 1e5;
int main() {
    int n,m; cin >> n >> m;
    bitset<mxN> visited; visited[0] = true;
    vi ans(m+1,-1);
    vi need(m+1);
    for(int time=1;time<=n;++time) {
        int t;
        ll x,y; cin >> t>> x >> y;
        for(auto i = visited._Find_first();i!=mxN;i=visited._Find_next(i)) {
            need[i] = y;
        }
        if(t==1) {
            for(int i=0;i<m;++i) {
                if(need[i]) {
                    int nxt  = i + (x+denum-1)/denum;
                    if(nxt>m) break;
                    if(!visited[nxt]) {
                        visited[nxt] = true;
                        ans[nxt] = time;
                    }
                    need[nxt] = max(need[nxt],need[i]-1);
                    need[i] = 0;
                }

            }
        } else {
                for(int i=0;i<m;++i) {
                    if(need[i]) {
                        ll nxt  = (i*x+denum-1)/denum;
                        if(nxt>m) break;
                        if(!visited[nxt]) {
                            visited[nxt] = true;
                            ans[nxt] = time;
                        }
                        need[nxt] = max(need[nxt],need[i]-1);
                    }
                need[i] = 0;
            }
        }
    }
    for(int i=1;i<=m;++i) {
        cout << ans[i] << ' ';
    } cout << '\n';
}