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
const string t[] = {"abc","bca", "cab", "cba","bac", "acb"};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    string s; cin >> s;
    // bad substrings: aa, bb, cc, aba, aca, bab, bcb, cac, cbc
    // first two characters fix everything 
    // Only allowable: abcabc and its rotations. cba and its rotations, 6 in total.

    array<vi,6> pref;
    int id=0;
    for(auto& p : pref) {
        p.resize(n+1);
        for(int j=0;j<n;++j) {
            p[j+1] = p[j] + (t[id][j%3]!=s[j]);
        }
        id++;
    }
    while(m--) {
        int l,r; cin >> l >> r,--l,--r;
        int ans = oo;
        for(auto& p : pref) {
            ans = min(ans, p[r+1]-p[l]);
        }
        cout << ans << '\n';
    }
}