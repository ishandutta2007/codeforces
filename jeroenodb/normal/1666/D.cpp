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
bool solve() {
        string s,t; cin >> s >> t;
    int n = s.size();
    unordered_map<char,vi> cnt;
    for(int i=0;i<n;++i) {
        cnt[s[i]].push_back(i);
    }
    vector<bool> good(n);
    for(int i=t.size()-1;i>=0;--i) {
        auto& v = cnt[t[i]];
        if(v.empty()) {
            return false;    
        } else {
            good[v.back()]=true;
            v.pop_back();
        }
    }
    string got;
    for(int i=0;i<n;++i) {
        if(good[i]) got.push_back(s[i]);
    }
    return t==got;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        auto tmp = solve();
        if(tmp) cout << "YES\n";
        else cout << "NO\n";
    }
}