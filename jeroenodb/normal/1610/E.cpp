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
const int mxN = 3e5+1, oo = 1e9;
int solve() {
    int n; cin >> n;
    vector<unsigned> a(n); for(auto& i : a) cin >> i;
    int best=1;
    int on = n;
    n = a.size();
    int last=1;
    for(int i=n-2;i>=0;--i) {
        int at=i,cur=1;
        if(a[i+1]!=a[i]) {
            while(true) {
                int j = lower_bound(a.begin()+at+1,a.end(),a[at]*2-a[i])-a.begin();
                if(j==n) 
                    break;
                at=j;
                cur++;
            }

        } else cur = last+1;
        best = max(best,cur);
        last=cur;
    }
    return on-best;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cout << solve() << '\n';
    }
}