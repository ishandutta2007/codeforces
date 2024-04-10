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
        int n; cin >> n;
        vi a(n); for(auto& i : a) cin >> i;
        vi b(n); for(auto& i : b) cin >> i;
        vi cnt(n+1);
        int j=0;
        for(int i=0;i<n;++i) {
            if(j==n or a[j]!=b[i]) {
                if(i>0 and b[i]==b[i-1] and cnt[b[i]]) {
                    cnt[b[i]]--;

                } else {
                    while(j<n and a[j]!=b[i]) {
                        cnt[a[j]]++;
                        ++j;
                    }
                    if(j==n) {
                        return false;
                    }
                    ++j;
                }
            } else {
                ++j;
            }
        }
        return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        auto res = solve();
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
}