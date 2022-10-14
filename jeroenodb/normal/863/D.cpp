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
    int n,q,m; cin >> n >> q >> m;
    vi a(n); for(auto& i : a) cin >> i;
    vector<array<int,3>> qs(q);
    for(auto& [t,l,r]: qs) {
        cin >> t >> l >> r;
    }
    reverse(all(qs));
    for(int i=0;i<m;++i) {
        int id; cin >> id;
        for(auto [t,l,r] : qs) {
            if(l<=id and id<=r) {
                if(t==2) {
                    int pos = id-l;
                    pos = r-l-pos;
                    id = pos+l;
                } else {
                    id--;
                    if(id<l) id=r;
                }
            }
        }
        cout << a[id-1] << ' ';
    } cout << '\n';
}