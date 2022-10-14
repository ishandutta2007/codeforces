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
    int n; cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i;
    sort(all(a));
    vi b(n,-1);
    {
        int i=0;
        for(auto v : a) {
            assert(b[i]==-1);
            b[i]=v;
            i+=2;
            if(i>=n) i=1;
        }
    }
    for(auto& i : b) assert(i!=-1);
    for(int i=0;i<n;++i) {
        if(!((b[(i+n-1)%n]<b[i] and b[i]>b[(i+1)%n]) or (b[(i+n-1)%n]>b[i] and b[i]<b[(i+1)%n]))) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    cout << b << '\n';
    sort(all(b));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}