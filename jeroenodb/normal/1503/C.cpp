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
const ll oo = 1e18;

struct city {
    int a,c;
    ll trans;
    bool operator<(const city& o)  {return a < o.a;} 
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<city> cs(n);
    ll ans = 0;
    for(auto& c : cs) {
        cin >> c.a >> c.c;
        ans+=c.c;
        c.trans = c.a+c.c;
    }
    sort(all(cs));
    struct straight {
        ll gone,val;
        bool operator<(const straight& o) const {
            return val>o.val;
        }
    };
    priority_queue<straight> pq2; 
    queue<straight> q;
    q.push({cs[0].trans, 0});
    pq2.push({cs[0].trans, -cs[0].trans});
    ll best = oo;
    ll dp=-1;
    for(auto& c : cs) {
        while(!pq2.empty() and pq2.top().gone <=c.a ) {
            best = min(best,pq2.top().val);
            pq2.pop();
        }
        while(!q.empty()) {
            if(q.front().gone<c.a) {
                q.pop();
            } else break;
        }
        dp = oo;
        if(!q.empty()) {
            dp = q.front().val;
        }
        dp = min(dp, c.a+best);
        pq2.push({c.trans, dp-c.trans});
        q.push({c.trans, dp});
    }
    cout << dp+ ans << endl;
    
    
}