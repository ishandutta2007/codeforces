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
    // AABBCCABABBCBC
    // AA -> ""
    // ABAB -> ""
    // BCBC -> ""
    // find minimum length string they can reach? Check if they the same? Stupid
    // BA <-> AABABB <-> AB
    // CB <-> BBCBCC <-> BC
    // B's can go to front, and then cancel with eachother
    // only parity of B matters
    // Left with ACACAAAC...CACAC string, can't do anything with that, except remove adjacent duplicates
    // Is this the solution?
    int t; cin >> t;
    auto canonical = [&](string s) {
        string res;
        bool b=false;
        for(auto i : s) {
            if(i=='B') b=!b;
            else {
                if(!res.empty() and res.back()==i) res.pop_back();
                else res.push_back(i);
            }
        }
        if(b) res.push_back('B');
        return res;
    };
    while(t--) {
        string u,v; cin >> u >> v;
        u = canonical(u),v=canonical(v);
        if(u==v) cout << "YES\n";
        else cout << "NO\n";
    }
}