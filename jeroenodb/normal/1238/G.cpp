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
    int n,m,c,cur; cin >> n >> m >> c >> cur;
    vector<array<int,3>> friends(n);
    for(auto& [t,a,b] : friends) cin >> t >> a >> b;
    friends.push_back({m,0,0});
    sort(all(friends));
    map<int,int> mp;
    mp[0]=cur;
    int prv=0;
    ll ans=0;
    for(auto  [t,a,b] : friends) {
        int need = t-prv;
        if(cur<need) {
            cout << "-1\n";
            return;
        }
        cur-=need;
        auto it = mp.begin();
        while(need and it->second<=need) {
            need-=it->second;
            ans+=(ll)it->first * it->second;
            it = mp.erase(it);
        }
        if(need) 
            ans+=(ll)it->first * need, it->second-=need;
        need = max(0, cur+a-c);
        cur=min(c,cur+a);
        mp[b]+=a;
        it = prev(mp.end());
        while(need and it->second<=need) {
            need-=it->second;
            mp.erase(it);
            it = prev(mp.end());
        }
        if(need)
            it->second-=need;
        prv=t;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}