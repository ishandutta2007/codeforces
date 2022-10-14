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
void solve() {
    int n,m; cin >> n >> m;
    vector a(m,vector(n,0));
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin >> a[j][i];
    auto b = a;
    sort(all(b));
    
   
    auto check = [&](int i, int j) {
        swap(a[i],a[j]);
        bool good=true;
        for(int i=0;i<m-1;++i) {
            for(int j=0;j<n;++j) {
                if(a[i][j]>a[i+1][j]) good=false;
            }
        }
        if(good) {
            cout << i+1 << ' ' << j+1 << '\n';
            return true;
        }
        swap(a[i],a[j]);
        return false;
    };
    #define ch(i,j) if(check(i,j)) return;
    ch(0,0);
    vi cand;
    for(int i=0;i<m;++i) {
        if(a[i]!=b[i]) {
            if(cand.empty()) {
                int j = i+1;
                while(j<m and a[i]!=b[j]) ++j;
                if(j<m) ch(i,j);
            }
            cand.push_back(i);
        }
    }
    if(cand.size()>1) {
        ch(cand[0],cand[1]);
    }
    cout << "-1\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}