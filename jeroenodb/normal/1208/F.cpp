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
const int LG = 21;
typedef array<int,2> ar2;
ar2 dp[1<<LG];
void update(ar2& a, ar2 b) {
    array<int,4> tmp;
    merge(all(a),all(b),tmp.begin());
    a = {tmp[2],tmp[3]};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vi a(n); for(auto& i : a) {
        cin >> i;
    }
    for(int i=0;i<n;++i) {
        update(dp[a[i]], {0,i+1});
    }
    // do SOS DP
    for(int i=0;i<LG;++i) {
        for(int j=0;j<1<<LG;++j) {
            if(j&1<<i) {
                update(dp[j^1<<i],dp[j]);
            }
        }
    }
    int best=0;
    for(int i=0;i+2<n;++i) {
        int cur = a[i];
        int want=0;
        for(int j=LG-1;j>=0;--j) {
            if((cur&1<<j)==0) {
                // check if possible
                if(dp[want|1<<j][0]>i+1) want|=1<<j;
            }
        }
        best = max(best,cur|want);
    }
    cout << best << '\n';


}