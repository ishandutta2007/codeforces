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
        vi a(n); for(auto& i : a) cin >> i;
        sort(all(a));
        vi same = {1};
        for(int i=1;i<n;++i) {
            if(a[i]==a[i-1]) same.back()++;
            else same.push_back(1);
        }
        // brute force is fast enough!
        int ans = oo;
        int m = same.size();
        for(int rep=0;rep<20;++rep) {
            int len = 1<<rep;
            int i=0;
            int cc=n;
            for(;i<m;++i) {
                if(same[i]>len) {
                    break;
                }
                len-=same[i];
                cc-=same[i];
            }
            int cost=len;
            // two other divisions
            auto costf = [&](int p) {
                int mylen = __lg(p+ (p==0));
                if(1<<mylen<p) mylen++;
                return (1<<mylen) - p;
            };
            int bb=0;
            for(int j=i;j<m;++j) {
                ans = min(ans,cost+costf(bb)+costf(cc));
                bb+=same[j];
                cc-=same[j];
            }
            ans = min(ans,cost+costf(bb)+costf(cc));
        }
        cout << ans << '\n';
    }
}