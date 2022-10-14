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
int cycles(vi v) {
    int n = v.size();
    vector<bool> vis(n);
    int ans=0;
    for(int i=0;i<n;++i) if(!vis[i]) {
        ans++;
        int at = i;
        while(!vis[at]) {
            vis[at]=true;
            at=v[at];
        }
    }
    return ans;
}
int calc(vi p, vi q) {
    int ans=0, n = p.size();
    for(int i=0;i<n;++i) {
        ans+=abs(q[i]-p[q[(i+1)%n]]);
    }
    return ans;
}
int main() {
    // for(int n=2;n<=5;++n) {
    //     debug(n);
    //     vi p(n); iota(all(p),0);
        
    //     do {
    //         vi q(n); iota(all(q),0);
    //         pair<int,vi> best = {oo,{}};
    //         do {
    //             best = min(best,{calc(p,q),q});

    //         } while(next_permutation(all(q)));
    //         assert(cycles(p)*2==2+best.first);
    //         // debug(best);
    //         vi qq =q;
    //         q.clear();
    //         vector<bool> vis(n);
    //         for(int i=0;i<n;++i) if(!vis[i]) {
    //             int at = i;
    //             vi cyc;
    //             while(!vis[at]) {
    //                 cyc.push_back(at);
    //                 vis[at]=1;
    //                 at = p[at];
    //             }
    //             if(i==0) q=cyc;
    //             else {
    //                 q.insert(find(all(q),i-1),all(cyc));
    //             }
    //         }
    //         reverse(all(q));
    //         if(cycles(p)*2!=calc(p,q)+2) {
    //             debug(p);
    //             debug(q);
    //             debug(qq);
    //             debug(cycles(p));
                
    //             debug(calc(p,q));
    //             exit(0);
    //         }
    //     } while(next_permutation(all(p)));
    // }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi p(n);
        for(auto& i : p) cin >> i,--i;
        vi q;
        vector<bool> vis(n);
        for(int i=0;i<n;++i) if(!vis[i]) {
            int at = i;
            vi cyc;
            while(!vis[at]) {
                cyc.push_back(at);
                vis[at]=1;
                at = p[at];
            }
            if(i==0) q=cyc;
            else {
                q.insert(find(all(q),i-1),all(cyc));
            }
        }
        reverse(all(q));
        // debug(cycles(p));
        // debug(calc(p,q));
        for(auto& i : q) ++i;
        cout << q << '\n';
    }
}