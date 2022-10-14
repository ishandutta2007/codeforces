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
    int n,k; cin >> n >> k;
    string s; cin >> s;
    // only 26 moves necessary
    // only order of character minimizes matters
    // string of <= 26 characters left
    // minimize first char
    int best[26];
    for(int i=0;i<26;++i) best[i]=i;
    for(auto c : s) {
        int a= c-'a';
        int most = min(k,a);
        int res=a;
        for(int i=0;i<=most;++i) {
            if(best[res]>best[a-i]) {
                res=a-i;
            }
        }
         k-=(a-res);
        res=best[res];
       
        cout << char(res+'a');
        for(int i=a;i>=res;--i) {
            best[i] = min(best[i],res);
        }
    }
    cout << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}