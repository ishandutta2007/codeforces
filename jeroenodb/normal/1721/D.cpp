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
typedef basic_string<int> vl;
void solve() {
    int n; cin >> n;
    vector<vl> a(1,vl(n,0)),b(1,vl(n,0));
    for(auto& i : a[0]) cin >> i;
    for(auto& i : b[0]) cin >> i;
    int ans=0;
    for(int j=29;j>=0;--j) {
        bool good=true;
        for(int k=0;k<a.size();++k) {
            int cnt[2][2] = {};
            auto& v = a[k];
            auto& w = b[k];
            for(auto i : v) cnt[0][i>>j & 1]++;
            for(auto i : w) cnt[1][i>>j & 1]++;
            if(cnt[0][1]!=cnt[1][0] or cnt[0][0]!=cnt[1][1]) {
                good=false;
                break;
            }
        }
        
        if(good) {
            vector<vl> na,nb;
            ans|=1<<j;
            for(int k=0;k<a.size();++k) {
                auto& v = a[k];
                auto& w = b[k];
                vl as[2] = {},bs[2] = {};
                for(auto i : v) as[i>>j & 1].push_back(i);
                for(auto i : w) bs[i>>j & 1].push_back(i);
                if(!as[0].empty()) na.push_back(as[0]),nb.push_back(bs[1]);
                if(!as[1].empty()) na.push_back(as[1]),nb.push_back(bs[0]);
            }
            swap(a,na),swap(b,nb);
        } 
    }
    cout << ans << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}