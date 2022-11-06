#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<pair<int,int>,pair<int,int>>
struct edge{
    int w,x,y;
};
struct edge2{
    int w,x,y,w2;
};
struct DisjointSet{
    vector<int>parent,sz;
    int size;
    void init(int n){
        size = n;
        parent.resize(n+1); sz.resize(n+1);
        for(int i = 1; i<=n; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        x = find(x); y = find(y);
        if(x==y)return;
        if(sz[x]<sz[y]){
            parent[x] = y;
            sz[y]+=sz[x];
        }
        else{
            parent[y] = x;
            sz[x]+=sz[y];
        }
    }
};
bool comp(edge a, edge b){
    return a.w<b.w;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    set<int>s;
    vector<edge>edges(m);
    for(int i = 0; i<m; i++){
        int x,y,w;
        cin >> x >> y >> w;
        edges[i] = {w,x,y};
        s.insert(w);
        s.insert(w-1);
        s.insert(w+1);
    }
    sort(edges.begin(),edges.end(),comp);
    for(int i = 0; i<m; i++){
        for(int j = i+1; j<m; j++){
            int mid = (edges[i].w+edges[j].w)/2;
            s.insert(mid-1);
            s.insert(mid+1);
            s.insert(mid);
        }
    }
    vector<int>sorted;
    for(int nxt: s){
        sorted.push_back(nxt);
    }
    vector<vector<int>>wt(sorted.size());
    vector<vector<int>>psa(sorted.size(),vector<int>(n));
    for(int t = 0; t<sorted.size(); t++){
        int l = -1; int r = 0;
        for(int i = m-1; i>=0; i--){
            if(edges[i].w<=sorted[t]){
                l = i;
                r = i+1;
                break;
            }
        }
        DisjointSet ds;
        ds.init(n);
        wt[t].push_back(-1);
        int cnt = 0;
        while(cnt<n-1){
            if(l>=0&&ds.find(edges[l].x)==ds.find(edges[l].y)){
                l--;continue;
            }
            if(r<m&&ds.find(edges[r].x)==ds.find(edges[r].y)){
                r++;continue;
            }
            if(l<0){
                cnt++;
                wt[t].push_back(edges[r].w);
                ds.Union(edges[r].x,edges[r].y);
                r++;
                continue;
            }
            if(r>=m){
                cnt++;
                wt[t].push_back(edges[l].w);
                ds.Union(edges[l].x,edges[l].y);
                l--;
                continue;
            }
            if(abs(edges[l].w-sorted[t])<=abs(edges[r].w-sorted[t])){
                wt[t].push_back(edges[l].w);
                ds.Union(edges[l].x,edges[l].y);
                l--;
                cnt++;
            }
            else{
                wt[t].push_back(edges[r].w);
                ds.Union(edges[r].x,edges[r].y);
                r++;
                cnt++;
            }
        }
        sort(wt[t].begin(),wt[t].end());
        for(int i = 1; i<n; i++){
            psa[t][i] = psa[t][i-1]+wt[t][i];
        }
    }
    int p,k,a,b,c;
    cin >> p >> k >> a >> b >> c;
    int totalans = 0;
    int prev = 0;
    for(int i = 1; i<=p; i++){
        int q;
        cin >> q;
        prev = q;
        int idx = lower_bound(sorted.begin(),sorted.end(),q)-sorted.begin();
        int ans = (int)1e18;
        if(idx>0){
            int ind = lower_bound(wt[idx-1].begin(),wt[idx-1].end(),q)-wt[idx-1].begin();
            int sum = (psa[idx-1][n-1]-psa[idx-1][ind-1])-(n-ind)*q;
            sum+=(ind-1)*q-psa[idx-1][ind-1];
            ans = min(ans,sum);
        }
        if(idx<sorted.size()){
            int ind = lower_bound(wt[idx].begin(),wt[idx].end(),q)-wt[idx].begin();
            int sum = (psa[idx][n-1]-psa[idx][ind-1])-(n-ind)*q;
            sum+=(ind-1)*q-psa[idx][ind-1];
            ans = min(ans,sum);
        }
        totalans^=ans;
    }
    //cerr << totalans << "\n";
    for(int i = 0; i<k-p; i++){
        int q = (prev*a+b)%c;
        prev = q;
        int idx = lower_bound(sorted.begin(),sorted.end(),q)-sorted.begin();
        int ans = (int)1e18;
        if(idx>0){
            int ind = lower_bound(wt[idx-1].begin(),wt[idx-1].end(),q)-wt[idx-1].begin();
            int sum = (psa[idx-1][n-1]-psa[idx-1][ind-1])-(n-ind)*q;
            sum+=(ind-1)*q-psa[idx-1][ind-1];
            ans = min(ans,sum);
        }
        if(idx<sorted.size()){
            int ind = lower_bound(wt[idx].begin(),wt[idx].end(),q)-wt[idx].begin();
            int sum = (psa[idx][n-1]-psa[idx][ind-1])-(n-ind)*q;
            sum+=(ind-1)*q-psa[idx][ind-1];
            ans = min(ans,sum);
        }
        //cout << ans << "\n";
        totalans^=ans;
    }
    cout << totalans << "\n";
    return 0;
}