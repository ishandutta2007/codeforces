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
    ll cnt[2][26] = {};
    cnt[0][0]=cnt[1][0]=1;
    int q; cin >> q;
    while(q--) {
        int d,k; cin >> d >> k;
        --d;
        string x; cin >> x;
        for(auto& c : x) cnt[d][c-'a']+=k;
        auto good = [&]() {
            int last=25;
            while(!cnt[1][last]) --last;
            if(last!=0) return true;
            // t only contains aaaaa's
            last = 25;
            while(!cnt[0][last]) --last;
            if(last!=0) return false;
            return cnt[0][0]<cnt[1][0];
        };
        if(good()) cout << "YES\n";
        else cout << "NO\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}