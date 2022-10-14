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
    vi d(n); for(auto& i : d) cin >> i;
    vi ord(n); iota(all(ord),0);
    sort(all(ord), [&](int i, int j) {return d[i]>d[j];});
    vector<array<int,2>> ans;
    for(int i=0;i<n-1;++i) {
        ans.push_back({2*ord[i],2*ord[i+1]});
    }
    deque<int> dist;
    for(int i : ord) {
        dist.push_back(2*i);
    }
    for(int i : ord) {
        ans.push_back({i*2+1,dist[d[i]-1]});
        dist.pop_front();
        if(d[i]-1==dist.size())
            dist.push_back(i*2+1);
        
    }
    for(auto [a,b] : ans) {
        cout << a+1 << ' ' << b+1 << '\n';
    }
    
}