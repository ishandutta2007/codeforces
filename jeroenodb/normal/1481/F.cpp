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
    int n,x; cin >> n >> x;
    vvi adj(n);
    for(int i=1;i<n;++i) {
        int p; cin >> p; --p;
        adj[p].push_back(i);
    }
    vector<pi> q; q.reserve(n);
    vvi level(n);
    q.push_back({0,0});
    int mxd = 0;
    for(int i=0;i<q.size();++i) {
        int at = q[i].first;
        int d = q[i].second;
        mxd = max(mxd,d);
        level[d].push_back(at);
        for(int to:adj[at]) {
            q.push_back({to,d+1});

        }
    }
    q.clear();
    // Try to make mxd+1 substrings
    vvi cnt(n+1);
    for(int d=0;d<=mxd;++d) {
        if(!level[d].empty()) {
            cnt[level[d].size()].push_back(d);
        }
    }
    vi from(x+1,-1);
    from[0] = oo;
    for(int w=1;w<n+1;++w) {
        if(!cnt[w].empty()) {
            int k = cnt[w].size();
            for(int j=0;j<w;++j) {
                int last = -oo;
                for(int i=j;i<=x;i+=w) {
                    if(from[i]==-1 and last + w*k >= i) {
                        from[i] = w;
                    } else if(from[i]!=-1) {
                        last = i;
                    }
                }
            }
        }
    }
    string ans;
    if(from[x]!=-1) {
        cout << mxd+1 << '\n';
        // Can make mxd+1 substrings
        ans = string(n,'b');
        int at = x;
        while(at) {
            int w = from[at];
            int d = cnt[w].back();
            cnt[w].pop_back();
            for(int i:level[d]) {
                ans[i] = 'a';
            }
            at-=w;
        }
    } else {
        cout << mxd+2 << '\n';
        // Answer must be mxd+2 substrings
        // One level of the tree can have a's and b's
        int left = n, as = x;
        ans = string(n,'?');
        for(int d=0;d<=mxd;++d) {
            int a = level[d].size();
            if(a<=as) {
                for(int i: level[d]) {
                    ans[i]='a';
                }
                as-=a;
            } else if(a <= left-as) {
                for(int i: level[d]) {
                    ans[i] = 'b';
                }
            } else {
                // Problem row
                char c = 'b'; int mult = 0, majority = left-as;
                if(as> left-as) {
                    majority = as;
                    mult=1;
                    c='a';
                }
                for(int i:level[d]) {
                    if(!adj[i].empty()) {
                        ans[i] = c;
                        as-=mult;
                        majority--;
                    } 
                }
                for(int i: level[d]) {
                    if(!adj[i].empty()) 
                        continue;
                    if(majority) {
                        ans[i] = c;
                        as-=mult;
                        majority--;
                    } else {
                        ans[i] = (c=='a'?'b':'a');
                        as-=!mult;
                    }
                }
            }
            left-=a;
        }
        assert(left==0 and as == 0);
    }
    cout << ans << '\n';
}