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
const int mxN = 1e5+2, oo = 1e9;
int ch(char c) {
    return c-'a';
}

array<int,26> tr[mxN];
int par[mxN],pp=1;
vi ds[mxN];

bitset<mxN> vis;
void add(string s) {
    int at=0;
    for(char c : s) {
        if(tr[at][ch(c)]==0) {
            par[pp]=at;
            tr[at][ch(c)]=pp++;
        }
        at = tr[at][ch(c)];
    }
    ds[at].push_back(0);
}
int ans=0;
void merge(int at) {
    int p = par[at];
    auto it  = find(all(ds[at]),0);
    if(it==ds[at].end()) {
        it = max_element(all(ds[at]));
        ans-=*it;
        *it=0;
    }
    if(at!=0) for(auto d : ds[at]) {
        ds[p].push_back(d+1);
    }
}
int main() {
    int n; cin >> n;
    for(int i=0;i<n;++i) {
        string s; cin >> s;
        ans+=s.size();
        add(s);
    }
    for(int i=pp-1;i>0;--i) merge(i);
    cout << ans << '\n';
}