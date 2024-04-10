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
    vi ans;
    auto go = [&](int i) {
        ans.push_back(i+1);
        reverse(a.begin(),a.begin()+i+1);
    };
    for(;n>1;n-=2) {
        if(a[n-2] == n-1 and a[n-1]==n) continue;
        for(int i=0;i<n;++i) {
            if(a[i]==n) {
                if(i%2==1) {
                    return false;
                }
                go(i);
                break;
            }
        }
        int i;
        for(i=0;i<n;++i) {
            if(a[i]==n-1) {
                if(i%2==0) {

                    return false;
                }
                if(i!=1) go(i-1);
                break;
            }

        }
        go(i+1);
        go(2);
        go(n-1);
    }
    cout << ans.size() << '\n';
    if(!ans.empty()) cout << ans << '\n';
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        if(!solve()) cout << "-1\n";
    }
}