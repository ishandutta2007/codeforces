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
        vvi b(n,vi(m));
        vector<tuple<int,int,int>> a(n*m);
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                cin >> b[i][j];
                a[i*m+j] = {b[i][j],i,j};
            }

        }
        sort(all(a));
        vector<vector<bool>> visited(n,vector<bool>(m));
        vvi ans(n,vi(m));
        for(int k=0;k<m;++k) {
            auto [l,i,j] = a[k];
            visited[i][j] = true;
            ans[i][k] = l;
        }
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(!visited[i][j]) {
                    for(int k=0;k<m;++k) {
                        if(ans[i][k]==0) {
                            ans[i][k] = b[i][j];
                            break;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;++i) {
            cout << ans[i] << '\n';
        }
    }
}