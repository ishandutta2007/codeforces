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
const int B = 200;
pi solve() {
    int n; cin >> n;
    vvi s(n);
    int m;
    { // coord compression and reading
        vi x;
        for(auto& v : s) {
            int k; cin >> k;
            v.resize(k);
            for(auto& i : v) cin >> i,x.push_back(i);
            sort(all(v));
        }

        sort(all(x));
        x.resize(unique(all(x))-x.begin());
        for(auto& v : s) for(auto& i : v) i = lower_bound(all(x),i)-x.begin();
        m = x.size();
    }
    
    vi ord(n); iota(all(ord),0);
    sort(all(ord),[&](int i, int j) {return s[i].size()<s[j].size();});
    { // big sets
        vector<bool> got(m);
        for(auto i : ord) {
            if(s[i].size()>=B) {
                // big set
                for(int y : s[i]) got[y]=true;
                for(int j : ord) {
                    if(j==i) break;
                    int cnt=0;
                    for(auto y : s[j]) {
                        cnt+=got[y];
                    }
                    if(cnt>=2) return {i+1,j+1};
                }
                for(int y : s[i]) got[y]=false;
            }
        }
    }
    vvi has(m);
    for(int i=0;i<n;++i) if(s[i].size()<B) {
        for(auto y : s[i]) has[y].push_back(i);
    }
    vi got(m,-1);
    for(int x=0;x<m;++x) if(has[x].size()>1) {
        for(auto i : has[x]) {
            for(auto y : s[i]) if(y!=x) {
                if(got[y]!=-1) 
                    return {i+1,got[y]+1};
                got[y]=i;
            }
        }
        for(auto i : has[x]) for(auto y : s[i]) got[y]=-1;
    }
    return {-1,-1};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        auto [a,b] = solve(); 
        if(a==-1) cout << "-1\n";
        else cout << a << ' ' << b << '\n';
    }
}