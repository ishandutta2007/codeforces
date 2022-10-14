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
    int n,m,k; cin >> n >> m >> k;
    map<string,int> ma;
    for(int i=0;i<n;++i) {
        string s; cin >> s;
        ma[s] = i;
    }
    vvi adj(n);
    vi deg(n);
    auto add = [&](int a, int b) {
        deg[b]++;
        adj[a].push_back(b);
    };
    for(int i=0;i<m;++i) {
        string t; cin >> t;
        int mt; cin >> mt;
        vector<int> v;
        for(int ss=0;ss<1<<k;++ss) {
            string tt = t;
            for(int j=0;j<k;++j) {
                if(ss & (1<<j)) {
                    tt[j] = '_';
                }
            }
            auto iter = ma.find(tt);
            if(iter != ma.end()) {
                v.push_back(iter->second);
            }
        }
        bool found = false;
        for(int j: v) {
            if(mt!=j+1) {
                add(j,mt-1);
            } else {
                found = true;
            }
        }
        if(!found) {
            cout << "NO\n";
            exit(0);
        }
    }
    queue<int> q;
    for(int i=0;i<n;++i) {
        if(!deg[i]) {
            q.push(i);
        }
    }
    vi ans; ans.reserve(n);
    while(!q.empty()) {
        int at = q.front(); q.pop();
        ans.push_back(at+1);
        for(int to: adj[at]) {
            if(--deg[to]==0) {
                q.push(to);
            }
        }
    }
    if(ans.size()!=n) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        reverse(all(ans));
        cout << ans << endl;
    }
}