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
    int n,m; cin >> n >> m;
    vi a(n); for(auto& i : a) cin >> i;
    ll total=ll(n)*(n+1)/2;
    auto change = [&](int i, int sgn) {
        if(a[i]!=a[i+1]) {
            total+=(ll)sgn*(i+1)*(n-1-i);
        }
    };
    auto add = [&](int i, int sgn) {
        if(i>0) change(i-1,sgn);
        if(i<n-1) change(i,sgn);
    };
    for(int i=0;i<n-1;++i) change(i,1);
    while(m--) {
        int i,x; cin >> i >> x;
        --i;
        add(i,-1);
        a[i]=x;
        add(i,1);
        cout << total << '\n';
    }
}