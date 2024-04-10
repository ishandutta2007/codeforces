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
    int n; cin >> n;
    ll sm=0;
    vi a((n+1)/2); for(auto& i : a) cin >> i,sm+=i;
    ll an; cin >> an;
    ll total = an*(n/2)+sm;
    if(total>0) {
        cout << n << '\n';
        exit(0);
    }
    if(an>0 or sm<=0) {
        cout << "-1\n";
        exit(0);
    }
    // total<=0, an<=0
    int best=n;
    for(int i=0;i<(n+1)/2;++i) {
        int j=-oo;
        if(sm>0) {
            j = (n+1)/2 + min((ll)n/2, (sm-1)/(-an));
        }
        best = min(best,j-i);
        if(best+i>=n) {
            cout << best << '\n';
            exit(0);
        }
        sm-=a[i];
    }
    cout << "-1\n";
}