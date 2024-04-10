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
struct maxq {
    deque<pair<ll,int>> q;
    ll lazy=0;
    void add(ll v,int i) {
        while(!q.empty() and q.back().first<v-lazy) q.pop_back();
        q.push_back({v-lazy,i}); 
    }
    void remove(int i) {
        if(!q.empty() and q.front().second == i) q.pop_front();
    }
    ll max() {
        if(q.empty()) return -oo;
        return q.front().first+lazy;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w,b,x; cin >> n >> w >> b >> x;
    int sm=0;
    vi cs(n);
    for(auto& i : cs) cin >> i, sm+=i;
    vi ws(n);
    for(auto& i : ws) cin >> i;
    vector<ll> dp[2];
    dp[0].resize(sm+1,-oo), dp[1].resize(sm+1,-oo);
    dp[0][0]=w;
    for(int k=0;k<n;++k) {
        auto& amount = cs[k];
        auto& cost = ws[k];
        maxq q;
        fill(all(dp[1]),-oo);
        for(int i=0,j=0;i<=sm;++i) {
            if(i-j>amount) {
                q.remove(j++);
            }
            dp[1][i] = max(q.max(),dp[0][i]);
            if(dp[1][i]>=0) dp[1][i] = min(w+(ll)b*i, dp[1][i]+x);
            if(dp[0][i]>=cost) q.add(dp[0][i],i);
            q.lazy-=cost;
        }
        swap(dp[0],dp[1]);
    }
    for(int i=sm;i>=0;--i) {
        if(dp[0][i]>=0) {
            cout << i << '\n';
            break;
        }
    }
}