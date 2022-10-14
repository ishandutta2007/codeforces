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
    vvi have(m);
    int cnt=0,cur=-1;
    for(auto& i : have) {
        int k; cin >> k;
        i.resize(k);
        for(auto& j : i) cin >> j;
        if(cnt==0) cur=i[0];
        if(cur==i[0]) cnt++;
        else cnt--;
    }
    int bad=0;
    for(auto& i : have) bad+=cur==i[0];
    int want = (m+1)/2;
    for(auto& i : have) if(bad>want) {
        if(i[0]==cur and i.size()>1) swap(i[0],i[1]),bad--;
    }
    if(bad>want) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(auto& i : have) cout << i[0] << ' ';
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}