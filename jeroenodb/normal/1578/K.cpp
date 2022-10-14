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
void solve() {
    int n; cin >> n;
    map<pi,vi> mp;
    auto get = [&](int a, int b) -> vi& {
        if(a>b) swap(a,b);
        return mp[{a,b}];
    };

    vector<array<int,3>> trs;
    for(int i=0;i<n-2;++i) {
        int a,b,c; cin >> a >> b >> c;
        trs.push_back({a,b,c});
        get(a,b).push_back(i),get(b,c).push_back(i),get(c,a).push_back(i);
    }
    vi res;
    int start;
    int a,b;
    for(auto [p,v] : mp) {
        if((int)v.size()==1) {
            start = v[0];
            a=p.first,b=p.second;
            break;
        }
    }
    res.push_back(a);
    for(int i=start;res.size()<n;) {
        res.push_back(b);
        // find next one
        
        
        while(true) {
            auto arr = trs[i];
            int nw = a^arr[0]^b^arr[1]^arr[2];
            auto& v = get(b,nw);
            if(v.size()>=2) {
                i = v[0]^v[1]^i;
                a=nw;
            } else {
                a=b;
                b=nw;
                break;
            }
        }
    }
    // find order?
    vi ord;
    vector<int> q;
    vi cnt(n);
    auto process = [&](int i) {
        cnt[i]++;
        if(cnt[i]==2) q.push_back(i);
    };
    for(int i=0;i<n-2;++i) {
        auto arr = trs[i];
        
        for(int j=0;j<3;++j) {
            int a=arr[j],b=arr[(j+1)%3];
            if(get(a,b).size()==1) {
                process(i);
            }
        }
    }
    for(int i=0;i<q.size();++i) {
        auto at = q[i];
        auto arr = trs[at];
        for(int j=0;j<3;++j) {
            int a=arr[j],b=arr[(j+1)%3];
            auto& v = get(a,b);
            if(v.size()==2) {
                process(v[0]^v[1]^at);
            }
        }
    }
    for(auto& i : q) i++;
    cout << res << '\n';
    cout << q << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}