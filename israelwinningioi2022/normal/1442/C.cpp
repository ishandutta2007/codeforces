#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 998244353;

int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b*b%MOD, p/2);
    return v * (p%2?b:1) %MOD;
}
int n,m;
vvi g,ag;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    g.resize(n), ag.resize(n);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--, b--;
        g[a].pb(b);
        ag[b].pb(a);
    }
    int LOG = 30;
    vvi dist(LOG, vi(n, INF));
    dist[0][0] = 0;
    priority_queue<pair<int,ii>> q; q.push({0,{0,0}});
    auto change = [&](int cur, int k, int d){
        if (k<LOG && dist[k][cur]>d){
            dist[k][cur] = d;
            q.push({-d,{k, cur}});
        }
    };
    while(q.size()){
        auto tmp = q.top(); q.pop();
        int d = -tmp.x, k = tmp.y.x, cur = tmp.y.y;
        if (dist[k][cur]!=d) continue;
        if (k%2){
            for(int nei:ag[cur]) change(nei, k, d+1);
        }
        else{
            for(int nei:g[cur]) change(nei, k, d+1);
        }
        change(cur, k+1, d+(1<<k));
    }
    int ans = INF;
    loop(i,0,LOG) if(dist[i][n-1]!=INF) {
        chkmin(ans, dist[i][n-1]);
    }
    if (ans==INF) {
        vvi totdist(n, vi(2,INF));
        priority_queue<pair<int,ii>> qq;
        totdist[0][0] = 0;
        qq.push({0,{0,0}});
        auto change2 = [&](int cur, int k, int d){
            if (totdist[cur][k%2]>d){
                totdist[cur][k%2] = d;
                qq.push({-d,{cur, k}});
            }
        };
        bool fin = 0;
        while(!fin){
            vector<pair<ii,int>> vec;
            while(qq.size()){
                auto tmp = qq.top(); qq.pop();
                int cur = tmp.y.x, k = tmp.y.y, d = -tmp.x;
                if (totdist[cur][k%2]!=d) continue;
                if (cur==n-1){
                    ans = (d + pp(2,k)+MOD-1)%MOD;
                    fin = 1;
                    break;
                }
                vec.pb({{cur, k},d});
                if (k%2){
                    for(int nei:ag[cur]) change2(nei, k, d+1);
                }
                else{
                    for(int nei:g[cur]) change2(nei, k, d+1);
                }
            }
            for(auto p:vec) change2(p.x.x, p.x.y+1, p.y);
        }
        //if (ans==53936080) cout<<"HI"<<endl;
    }
    else ans = ans%MOD;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
7 6
2 1
3 2
4 3
4 5
6 5
6 7



4 3
2 1
2 3
4 3


*/