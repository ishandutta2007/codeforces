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
    int n; cin >> n;
    int nn=n;
    // first part
    if(n%2==1) cout << "NO\n";
    else {
        cout << "YES\n";
        //
        vi ans(n);
        while(n>0) {
            int k = __lg(n);
            int full = (1<<k)-1;
            for(int i=1<<k;i<=n;++i) {
                int to = ~i&full;
                ans[i-1]=to;
                ans[to-1]=i;
            }
            n=~n&full;
            n--;
        } 
        cout << ans << '\n';
    }
    // second part
    n=nn;
    if(n<6 or (n&(-n))==n) {
        cout << "NO\n";
        exit(0);
    }
    cout << "YES\n";
    vi ans = {3, 6, 2, 5, 1, 4};
    ans.reserve(n);
    auto p1 = [&]() {
        auto& to = ans.back();
        ans.push_back(to);
        to=ans.size();
    };
    if(n>6) p1();
    while(ans.size()+2<=n) {
        ans.push_back(ans.size()+2);
        ans.push_back(ans.size());
    }
    if(ans.size()<n) p1();
    cout << ans << '\n';


}