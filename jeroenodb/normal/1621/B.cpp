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
const int mxN = 1e5+1;
const ll oo = 1e10+1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        // leftmost cheapest
        // rightmost cheapest
        int lm=1e9 + 2,rm=-1e9 - 2;
        ll a=oo,b=oo,c=2*oo;
        for(int i=0;i<n;++i) {
            int l,r; ll cc;
            cin >> l >> r >> cc;
            
            if(l<lm) a=oo,c=oo,lm=l;
            if(r>rm) b=oo,c=oo,rm=r;
            if(l==lm) a=  min(a,cc);
            if(r==rm) b = min(b,cc);
            if(l==lm and r==rm) c = min(c,cc);
            cout << min(a+b,c) << '\n';
        }

    }
}