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
const int mxN = 1e6+1, oo = 1e9;
struct DSU{
    vi sz,mx;
    DSU(int n) {
        sz.assign(n,-1);
        mx.resize(n);
        iota(all(mx),0);
    }
    void link(int a, int b) {
        if(sz[a]>sz[b]) {
            swap(a,b);
        }
        sz[a] +=sz[b];
        mx[a] = max(mx[a],mx[b]);
        sz[b] = a;
    }
    bool unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb);
        return pa!=pb;
    }
    int find(int a) {
        if(sz[a]<0) return a;
        return sz[a] = find(sz[a]);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    vvi remove(n+3);
    {
        // calculate times
        int last[2] = {n,n};
        for(int i=n-1;i>=0;--i) {
            int jmp;
            if(s[i]=='?') {
                jmp = max(last[0],last[1])-i;
            } else {
                bool one = s[i]-'0';
                jmp = last[!one]-i;
                remove[jmp+1].push_back(i);
                last[one]=i;
            }
            remove[jmp+1].push_back(i);
        }
    }
    DSU dsu(n+1);
    
    for(int x=1;x<=n;++x) {
        for(auto r : remove[x]) dsu.unite(r,r+1);
        int at = -x;
        int ans=-1;
        while(at<n) {
            ans++;
            at = dsu.mx[dsu.find(at+x)];
        }
        cout << ans << ' ';
    }


}