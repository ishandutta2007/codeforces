#pragma GCC optimize("Ofast")
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
const int mxN = 1e7+1, oo = 1e9;
const int store=1e7 + 1;
int sm[store] = {}, ans[store];
void makesieve() {
    fill(ans,ans+store, oo);
    for(int i = 1; i < store;++i) {
        for(int j = i;j<store;j+=i) {
            sm[j]+=i;
        }
        if(sm[i]<store) ans[sm[i]] = min(ans[sm[i]], i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    makesieve();
    int t; cin >> t;
    while(t--) {
        int c; cin >> c;
        cout << (ans[c]==oo?-1:ans[c]) << '\n';
    }
}