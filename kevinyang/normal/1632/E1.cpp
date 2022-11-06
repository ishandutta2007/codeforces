#include <bits/stdc++.h>
using namespace std;
#define int long long
bool comp(pair<int,int>a, pair<int,int>b){
    return a.first-a.second<b.first-b.second;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>>adj(n+1);
        for(int i = 1; i<n; i++){
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int>f(n+1,(int)1e18);
        if(true){
            vector<bool>vis(n+1);
            vector<int>dis(n+1);
            queue<int>q;
            q.push(1);
            vis[1] = true;
            while(q.size()){
                int cur = q.front(); q.pop();
                for(int nxt: adj[cur]){
                    if(vis[nxt])continue;
                    vis[nxt] = true;
                    q.push(nxt);
                    dis[nxt] = dis[cur]+1;
                }
            }
            int mx = 0;
            for(int i = 1; i<=n; i++){
                mx = max(mx,dis[i]);
            }
            for(int i = 1; i<=n; i++){
                f[i] = mx;
            }
        }
        for(int i = 2; i<=n; i++){
            vector<bool>vis(n+1);
            vector<int>dis(n+1);
            queue<int>q;
            q.push(i);
            vis[i] = true;
            while(q.size()){
                int cur = q.front(); q.pop();
                if(cur==1)continue;
                for(int nxt: adj[cur]){
                    if(vis[nxt])continue;
                    vis[nxt] = true;
                    q.push(nxt);
                    dis[nxt] = dis[cur]+1;
                }
            }
            vector<bool>vis2(n+1);
            vector<int>dis2(n+1);
            q.push(1);
            vis2[1] = true;
            while(q.size()){
                int cur = q.front(); q.pop();
                for(int nxt: adj[cur]){
                    if(vis[nxt]||vis2[nxt])continue;
                    vis2[nxt] = true;
                    q.push(nxt);
                    dis2[nxt] = dis2[cur]+1;
                }
            }
            vector<bool>vis3(n+1);
            vector<int>dis3(n+1);
            q.push(1);
            vis3[1] = true;
            while(q.size()){
                int cur = q.front(); q.pop();
                if(cur==i)continue;
                for(int nxt: adj[cur]){
                    if(vis3[nxt])continue;
                    vis3[nxt] = true;
                    q.push(nxt);
                    dis3[nxt] = dis3[cur]+1;
                }
            }
            vector<int>pre(n+1);
            int mxboth = 0;
            for(int i = 1; i<=n; i++){
                if(vis3[i]&&vis[i]){
                    mxboth = max(mxboth,dis3[i]);
                }
            }
            vector<bool>vis4(n+1);
            int mxall = 0;
            queue<int>q1;
            bool odd = false;
            vector<pair<int,int>>arr;
            int curmx = 0;
            for(int i = 1; i<=n; i++){
                if(vis3[i]&&vis[i]){
                    arr.push_back({dis3[i],dis[i]});
                }
            }
            sort(arr.begin(),arr.end(),comp);
            vector<int>suf(arr.size()+5);
            for(int i = (int)arr.size()-1; i>=0; i--){
                suf[i] = max(suf[i+1],arr[i].second);
            }
            int cur = 0;
            int old = i;
            for(int i = 1; i<=n; i++){
                while(cur<arr.size()&&arr[cur].first-(arr[cur].second+i)<=0){
                    curmx = max(curmx,arr[cur].first);
                    cur++;
                }
                if(old==7){
                    //cout << i << " " << curmx << " " << cur << "\n";
                }
                pre[i] = max(curmx,suf[cur]+i);
            }
            /*
            for(int i = 1; i<=n; i++){
                pre[i] = (curmx+i)/2;
                pre[i] = min(pre[i],mxall);
            }
            /*
            for(int i = 1; i<=n; i++){
                for(int cur: q1){
                    for(int nxt: adj[cur]){
                        if(vis4[nxt])continue;
                        if(i+dis[nxt]<=dis3[nxt])continue;
                        curmx = max(curmx,dis3[nxt]);
                        vis4[nxt] = true;
                    }
                }
                pre[i] = curmx;
                q1.clear();
                for(int nxt: q2){
                    q1.push_back(nxt);
                }
                q2.clear();
            }
            */
            /*
            if(i==7){
                for(int i = 1; i<=n; i++){
                    cout << pre[i] << " ";
                }
                cout << "\n";
                for(pair<int,int>nxt: arr){
                    cout << nxt.first << " " << nxt.second << "\n";
                }
            }
            */
            int mxdis1 = 0;
            int mxaway = 0;
            for(int j = 1; j<=n; j++){
                mxdis1 = max(mxdis1,dis2[j]);
                if(!vis3[j]){
                    mxaway = max(mxaway,dis[j]);
                }
            }
            for(int j = 1; j<=n; j++){
                if(j>=dis[1])break;
                int v = (j+dis[1])/2;
                int val = max({mxdis1,mxaway+j,pre[j]});
                f[j] = min(f[j],val);
            }
        }
        for(int i = 1; i<=n; i++){
            cout << f[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}