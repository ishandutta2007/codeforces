#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>>a(n+1);
        vector<pair<int,int>>b(n+1);
        int mxa = 0; int idxa = 0;
        int mxb = 0; int idxb = 0;
        for(int i = 1; i<=n; i++){
            int x;
            cin >> x;
            a[i] = {x,i};
            if(x>mxa){
                mxa = x;
                idxa = i;
            }
        }
        for(int i = 1; i<=n; i++){
            int x;
            cin >> x;
            b[i] = {x,i};
            if(x>mxb){
                mxb = x;
                idxb = i;
            }
        }
        //cerr << "nae\n";
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<vector<int>>adj(n+1);
        for(int i = 2; i<=n; i++){
            adj[a[i-1].second].push_back(a[i].second);
            adj[b[i-1].second].push_back(b[i].second);
        }
        vector<bool>ans(n+1);
        queue<int>q;
        vector<bool>vis(n+1);
        vis[idxa] = true; vis[idxb] = true;
        q.push(idxa); if(idxa!=idxb)q.push(idxb);
        //cerr << "nae3\n";
        while(q.size()){
            int cur = q.front(); q.pop();
           // cerr << "nae2\n";
            //cerr << cur << "\n";
            for(int nxt: adj[cur]){
               //cerr << "nae3\n";
                if(!vis[nxt]){
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        for(int i = 1; i<=n; i++){
            cout << vis[i];
        }
        cout << "\n";
    }
    return 0;
}