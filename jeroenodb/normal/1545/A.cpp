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
const int mxN = 1e5+5, oo = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi a(n); for(auto& i : a) cin >> i;
        vi order(n); iota(all(order),0);
        sort(all(order), [&](int c,int d){return a[c]<a[d];});
        bool bad=false;;
        int prev=-1, j=0,odds=0;
        for(auto i : order) {
            bool mydir = abs(i-j)%2==1;
            if(a[i]!=prev and odds!=0) {
                bad=true;
                break;
            }
            if(j%2==0) odds++;
            else odds--;
            if((mydir^j)%2) odds++;
            else odds--;
            prev=a[i];
            j++;
        }
        if(bad or odds!=0) {
            cout << "NO\n";
        } else cout << "YES\n";
    }
}