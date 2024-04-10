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
const int mxN = 1e5+1;
const ll oo = 2e18;
vvi adj;
vector<char> type;
vector<bool> bad;
int parse() {
    char c;
    cin >> c;
    // open parenthesis
    if(c=='*') {
        int at = adj.size();
        adj.push_back({});
        type.push_back(c);
        return at;
    }
    int at = adj.size();
    adj.push_back({});
    type.push_back('?');
    auto tmp = parse();
    adj[at].push_back(tmp);
    
    cin >> type[at];
    do {
        auto tmp = parse();
        adj[at].push_back(tmp);
        cin >> c;
    } while(c!=')');
    return at;

}
void setbad(int at) {
    if(bad[at]) return;
    bad[at]=true;
    for(int to : adj[at]) {
        setbad(to);
    }
}
ll dfs(int at) { // price per resistance unit DP
    if(type[at]=='S') {
        vector<ll> cs;
        for(int to : adj[at]) {
            cs.push_back(dfs(to));
        }
        int j = min_element(all(cs))-cs.begin();
        for(int i=0;i<adj[at].size();++i) if(i!=j) {
            setbad(adj[at][i]);
        }
        return cs[j];
    } else if(type[at]=='P') {
        ll ans=0;
        for(int to : adj[at]) {
            ans+=dfs(to);
        }
        return ans;
    } else return 1;
}
int main() {
    // maak een boom
    int t; cin >> t;
    while(t--) {
        int r; cin >> r;
        adj.clear();
        type.clear();
        int root = parse();
        bad.assign(adj.size(),{});
        auto total = dfs(root);
        cout << "REVOLTING";
        for(int i=0;i<adj.size();++i) if(type[i]=='*') {
            if(bad[i]) cout << " 0";
            else cout << ' ' << total*r; 
        } cout << '\n';
    }
}