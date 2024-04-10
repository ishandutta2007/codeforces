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
    int n,q; cin >> n >> q;
    vector<vector<pi>> to(n);
    vector<unsigned> zero(n),one(n);
    while(q--) {
        unsigned i,j,x; cin >> i >> j >> x;
        --i,--j;
        if(i>j) swap(i,j);
        zero[i]|=~x;
        zero[j]|=~x;
        if(i==j) {
            one[i]|=x;
        }else to[i].push_back({j,x});
    }
    
    for(int i=0;i<n;++i) {
        int a=0;
        for(int j=29;j>=0;--j) {
            int need= (one[i])&1<<j;
            for(auto [t,x] : to[i]) {
                if( (1<<j & x) and (zero[t] & 1<<j)) {
                    need |= 1<<j;
                }
            }
            a^=need;
            if(!need) {
                for(auto [t,x] : to[i]) {
                    if( (1<<j & x)) {
                        one[t]|=1<<j;
                    }
                }
            }
        }
        cout << a << ' ';
    }
    cout << '\n';

}