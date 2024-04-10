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
typedef vector<vector<pi>> graph;
graph solvepw(int k) {
    if(k==0) {
        graph res(2);
        res[0] = {{1,1}};
        return res;
    }
    auto res = solvepw(k-1);
    res.push_back({});
    int n = res.size();
    res[0].emplace_back(n-1,1);
    for(int i=1;i<k+1;++i) {
        res[i].emplace_back(n-1,1<<(i-1));
    }
    return res;
}
graph solve(int R) {
    int k = __lg(R);
    auto res = solvepw(k);
    if((1<<k) == R) return res;
    res.push_back({});
    R--;
    int n = res.size();
    res[0].emplace_back(n-1,1);
    for(int i=0;i<=k;++i) if(1<<i & R) {
        R^= (1<<i);
        res[i+1].emplace_back(n-1,R+1);
    }
    return res;
};
void print(graph& adj) {
    cout << "YES\n";
    int n = adj.size(),m=0;
    for(auto& i : adj) m+=i.size();
    cout << n << ' ' << m << '\n';
    for(int i=0;i<n;++i) {
        for(auto [to,w]: adj[i]) {
            cout << i+1 << ' ' << to+1 << ' ' << w << '\n';
        }
    }
}
map<int,int> mp;
void check(int at, int d,graph& g) {
    if(at==g.size()-1) {
        mp[d]++;
    }
    for(auto [to,w] : g[at]) {
        check(to,w+d,g);
    }
}
int main() {
    int L,R; cin >> L >> R;
    auto res = solve(R-L+1);
    for(auto& [to,w]: res[0]) w+=L-1;
    print(res);
    map<int,int> want;
    for(int i=L;i<=R;++i) want[i]++;
    // check(0,0,res);
    // debug(mp);
    // assert(mp==want);
}