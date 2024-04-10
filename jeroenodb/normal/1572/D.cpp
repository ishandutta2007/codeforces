#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll,int> pil;
const int N = 20, PWN = 1<<N;
ll oo = 1e18;
int a[PWN];
typedef array<int,3>  el;
bitset<PWN> color,vis;
vi vis2;

int match[PWN],par[PWN];
ll dist[PWN];
int pp=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    for(int i=0;i<1<<n;++i) {
        cin >> a[i];
    }
    int lim = max(1000,10+2*k*n);
    priority_queue<el> pq;
    for(int i=0;i<1<<n;++i) {
        if(__builtin_popcount(i)%2==0) {
            color[i]=true;
            for(int j=0;j<n;++j) {
                int to = (1<<j)^i;
                el e = {-a[i]-a[to],i,to};
                pq.push(e);
                if((int)pq.size()>lim) {
                    pq.pop();
                }
            }
        }
    }
    vector<el> paths;
    fill(match,match+ (1<<n),-1);
    while(!pq.empty()) {
        auto c = pq.top();
        c[0]=-c[0];
        paths.push_back(c);
        pq.pop();
    }
    ll ans=0,realans=0;
    while(k--) {
        el best = {-1,-1,-1};
        while(!paths.empty()) {
            auto i = paths.back();
            if(vis[i[1]] or vis[i[2]]) {
                paths.pop_back();
            } else break;
        }
        if(!paths.empty()) best = paths.back();
        queue<int> q;
        auto relax = [&](int at , int from, ll d, bool add=true) {
            if(d>dist[at]) {
                dist[at]=d;
                par[at]=from;
                if(add) q.push(at);
            }
        };
        for(auto at : vis2) {
            dist[at]=-oo;
            if(!color[at]) for(int j=0;j<n;++j) {
                int to = at^(1<<j);
                if(to!=match[at] and match[to]==-1) relax(at,to,a[at]+a[to],false); 
            }
            if(!color[at] and dist[at]!=-oo) q.push(at);
        }
        pil best2 = {-oo,-1};
        while(!q.empty()) {
            auto at = q.front();q.pop();
            if(dist[at]==-oo) continue;
            for(int j=0;j<n;++j) {
                int to = at^(1<<j);
                ll d=-oo;
                if(color[at] and to!=match[at]) d = a[at]+a[to]; 
                else if(!color[at] and to==match[at]) d=-a[at]-a[to];
                
                if(d!=-oo) {
                    if(!vis[to]) {
                        assert(color[at]);
                        pil cur = {d+dist[at],to};
                        if(cur>best2) {
                            best2 = cur;
                            par[to]=at;
                        }
                    } else relax(to,at,d+dist[at]);
                }
            }
        }
        if(best2.first==-oo and best[0]==-1) {
            break;
        }
        auto doMatch = [&](int b, int c) {
            if(!vis[c]) vis2.push_back(c);
            if(!vis[b]) vis2.push_back(b);
            vis[c]=true;
            vis[b]=true;
            match[c]=b;
            match[b]=c;
        };
        if(best2.first>best[0]) {
            ans+=best2.first;
            int at = best2.second;
            bool even=true;
            while(true) {
                int to = par[at];
                bool done = !vis[to];
                if(even) doMatch(at,to);
                if(done) break;
                at=to;
                even = !even;
            }
        } else {
            doMatch(best[1],best[2]);
            ans+=best[0];
        }
        realans = max(ans,realans);
    }
    cout << realans << '\n';

    
}