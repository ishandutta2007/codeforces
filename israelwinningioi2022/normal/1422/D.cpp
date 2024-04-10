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
const int INF = 4e18;

int getd(ii a, ii b){
    return min(abs(a.x-b.x), abs(a.y-b.y));
}
int reald(ii a, ii b){
    return abs(a.x-b.x) + abs(a.y-b.y);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int l, n; cin>>l>>n;
    ii s,e; cin>>s.x>>s.y>>e.x>>e.y;
    vii ps(n);
    loop(i,0,n) cin>>ps[i].x>>ps[i].y;
    vii xs(n), ys(n);
    loop(i,0,n) xs[i] = {ps[i].x, i}, ys[i] = {ps[i].y, i};
    sort(all(xs)); sort(all(ys));
    vi posx(n), posy(n);
    loop(i,0,n) posx[xs[i].y] = i, posy[ys[i].y] = i;
    vi dist(n);
    priority_queue<ii> q;
    loop(i,0,n){
        dist[i] = getd(s, ps[i]);
        q.push({-dist[i],i});
    }
    while(q.size()){
        ii tmp = q.top(); q.pop();
        int i = tmp.y, d = -tmp.x;
        if (d!=dist[i]) continue;
        int xi = posx[i], yi = posy[i];
        vi vec;
        if (xi) vec.pb(xs[xi-1].y);
        if (xi+1<n) vec.pb(xs[xi+1].y);
        if (yi) vec.pb(ys[yi-1].y);
        if (yi+1<n) vec.pb(ys[yi+1].y);
        for(auto j:vec){
            int v = d + getd(ps[i], ps[j]);
            if (dist[j] > v){
                dist[j] = v;
                q.push({-dist[j], j});
            }
        }
    }
    int ans = reald(s,e);
    loop(i,0,n) chkmin(ans, dist[i] + reald(ps[i], e));
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
5 3
1 1 5 5
1 2
4 1
3 3

*/