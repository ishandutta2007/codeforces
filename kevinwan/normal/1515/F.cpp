#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=3e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();


struct edge{
    int a,b;
    int ind;
};

int n,m;
ll x,v[mn];
vector<edge> g[mn];
set<int>s;


int p[mn],ct;
int f(int x){return p[x]==x?x:(p[x]=f(p[x]));}
void u(int a,int b){
    a=f(a),b=f(b);
    if(g[a].size()<g[b].size())swap(a,b);
    for(edge e:g[b])g[a].push_back(e);
    g[b].clear();
    v[a]+=v[b]-x;
    v[b]=0;
    p[b]=a;
    if(v[a]>=x)s.insert(a);
    else s.erase(a);
    s.erase(b);
}
    


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>m>>x;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        sum+=v[i];
        if(v[i]>=x)s.insert(i);
    }
    if(sum<ll(n-1)*x){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    vector<edge> ed;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge e={a,b,i};
        g[a].push_back(e);
        g[b].push_back(e);
        ed.push_back(e);
    }
    int cur=0;
    iota(p,p+mn,0);
    vi ans;
    for(int i=0;i<n-1;i++){
        if(s.size()){
            int a=*s.begin();
            while(g[a].size()){
                edge e=g[a].back();
                if(f(e.a)==f(e.b)){
                    g[a].pop_back();
                    continue;
                }

                u(e.a,e.b);
                ans.push_back(e.ind);
                break;
            
            }
        }
        else{
            while(f(ed[cur].a)==f(ed[cur].b))cur++;
            u(ed[cur].a,ed[cur].b);
            ans.push_back(ed[cur].ind);
        }
    }
    for(int x:ans)printf("%d\n",x+1);
}