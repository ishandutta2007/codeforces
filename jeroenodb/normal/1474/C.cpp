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
        int n; cin >> n;
        vi a(n*2);
        for(auto& i :a) cin >> i;
        sort(all(a));
        bool fin=false;
        for(int j=0;j<2*n-1;++j) {
            vector<pi> ops;
            multiset<int> have(all(a));
            int x = a[j]+a[2*n-1];
            bool bad=false;
            while(!have.empty()) {
                auto it = prev(have.end());
                auto big = *it;
                have.erase(it);
                it = have.find(x-big);
                if(it!=have.end()) {
                    x = big;
                    ops.push_back({*it,x});
                    have.erase(it);
                } else {
                    bad=true;
                    break;
                }
            }
            if(bad) continue;
            cout << "YES\n";
            cout << a[j]+a[2*n-1] << '\n';
            fin=true;
            for(auto [c,d] : ops) {
                cout << c << ' ' << d << '\n';
                
            }
            break;
        }
        if(!fin) cout << "NO\n";
    }
}