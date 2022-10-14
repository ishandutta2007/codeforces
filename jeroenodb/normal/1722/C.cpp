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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<string,int> cnt;
        array<vector<string>,3> guys = {};
        for(auto& v : guys) {
            v.resize(n);
            for(auto& i : v) {
                cin >> i;
                cnt[i]++;
            }
        }
        for(auto& v : guys) {
            int ans=0;
            for(auto& i : v) {
                if(cnt[i]==1) ans+=3;
                else if(cnt[i]==2) ans++;
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
}