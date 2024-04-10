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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int k; cin >> k;
        vi a(n); for(auto& i : a) cin >> i;
        map<int,int> cnt;
        for(auto& i : a) cnt[i]++;
        int cur=0,prv=-oo;
        pi ans = {-1,-1};
        for(auto [i,c] : cnt) {
            if(c>=k) {
                if(prv!=i-1) cur=0;
                cur++;
                ans = max(ans,pi{cur,i});
            } else cur=0;
            prv = i;
        }
        if(ans.first==-1) {
            cout << "-1\n";
        } else cout << ans.second-ans.first+1 << ' ' << ans.second << '\n';
    }
}