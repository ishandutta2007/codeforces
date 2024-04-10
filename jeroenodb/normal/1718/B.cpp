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
bool solve() {
    int k; cin >> k;
    ll sm=0;
    priority_queue<pi> c;
    for(int i=0;i<k;++i) {
        int a; cin >> a;
        c.push({a,i});
        sm+=a;
    }
    vector<ll> f = {0,1};
    sm-=1;
    while(sm>0) {
        f.push_back(f.back()+f[f.size()-2]);
        sm-=f.back();
    }
    f.erase(f.begin());
    if(sm<0 or f.size()<c.size()) {
        return false;
    }
    

    int last=-1;
    pi wait = {-1,-1};
    while(!f.empty() and !c.empty()) {
        auto [v,id] = c.top(); c.pop();
        if(id==last or v<f.back()) {
            if(wait == pi{-1,-1} and !c.empty()) {
                wait = {v,id};
                continue;
            }
            return false;
        }
        if(wait.first!=-1) c.push(wait), wait = {-1,-1};
        v-=f.back();
        f.pop_back();
        last=id;
        if(v>0) c.push({v,id});
    }
    return (f.empty() and c.empty());

    

}
int main() {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
       if(solve()) {
            cout << "YES\n";
       } else cout << "NO\n";
    }
    
}