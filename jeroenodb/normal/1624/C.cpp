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
        vi cnt(n+1);
        for(int i=0;i<n;++i) {
            int a; cin >> a;
            while(a>n) a/=2;
            cnt[a]++;
        }
        bool bad=false;
        for(int i=n;i>=1;--i) {
            if(!cnt[i]) bad=true;
            else cnt[i/2]+=cnt[i]-1;
        }
        if(bad) cout << "NO\n";
        else cout << "YES\n";

    }
}