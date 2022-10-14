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
void print(ll a, ll b, bool plus=true) {
    cout << a  << (plus?" + ":" ^ ") << b << '\n';
}
vector<tuple<ll,ll,bool>> ops;
set<ll> s;
ll op(ll a, ll b, bool plus=true) {
    ll res = plus?a+b:a^b;
    if(s.count(res)) return res;
    ops.emplace_back(a,b,plus);
    s.insert(res);
    return res;
}
void solve(ll x, ll pw) {
    if(x==1) return;
    // pw is one greater than x
    ll prev=x;
    while(prev*2!=pw) {
        prev = op(prev,prev);
        if(pw&prev) prev = op(prev,pw,0);
    }
    
    solve(x&prev?op(x,prev,0):x,prev);
}
void solve(ll x) {
    if(x==1) return;
    if(x%4==3) {
        solve(op(op(x,x),x,false));
        return;
    }
    int lg = __lg(x);
    ll xx=x;
    for(int i=0;i<lg;++i) {
        xx = op(xx,xx);
    }
    ll tmp[] = {op(xx,x),op(xx,x,0)};
    ll pw = op(tmp[0],tmp[1],0);
    solve(x,pw);
}
int main() {
    ll x; cin >> x;
    solve(x);
    cout << ops.size() << endl;
    for(auto& [a,b,plus] : ops) {
        print(a,b,plus);
    }
}