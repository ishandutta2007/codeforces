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
    int n,x; cin >> n >> x;
    vi a(n); for(auto& i : a) cin >> i;
    map<int,array<int,32>> mp;
    for(auto i : a) {
        int tmp=0;
        while(i%x==0) i/=x,tmp++;
        mp[i][tmp]++;
    }
    ll ans=0;
    for(auto& [s, v] : mp) {

        for(int i=1;i<32;++i) {
            int add = max(0, v[i-1]-v[i]);;
            ans+=add;
            v[i]+=add;
            v[i]-=v[i-1];
            v[i-1]=0;
            assert(v[i-1]==0);
        }
    }
    cout << ans << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}