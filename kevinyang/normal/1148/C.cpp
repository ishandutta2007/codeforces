#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>arr(300005);
vector<pair<int,int>>edges;
int n;
void solve(){
    vector<bool>vis(n+1);
    for(int i = 1; i<=n; i++){
        if(vis[i])continue;
        queue<int>q;
        q.push(i);
        vis[i] = true;
        stack<pair<int,int>>s;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            int prev = cur;
            int nxt = arr[cur];
            cur = arr[cur];
            if(vis[cur])break;
            q.push(cur);
            vis[cur] = true;
            s.push({prev,cur});
        }
        //cerr << s.size() << "\n";
        while(s.size()){
            edges.push_back(s.top());
            s.pop();
        }
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    vector<pair<int,int>>ans;
    solve();
    for(pair<int,int>nxt: edges){
        int x = nxt.first; int y = nxt.second;
        if(abs(x-y)*2>=n){
            ans.push_back({x,y});
        }
        else{
            if(x>y)swap(x,y);
            if(x<=n/2&&y<=n/2){
                ans.push_back({x,n});
                ans.push_back({y,n});
                ans.push_back({x,n});
            }
            else if(x>n/2&&y>n/2){
                ans.push_back({1,x});
                ans.push_back({1,y});
                ans.push_back({1,x});
            }
            else if(x<=n/2&&y>n/2){
                ans.push_back({x,n});
                ans.push_back({1,n});
                ans.push_back({1,y});
                ans.push_back({1,n});
                ans.push_back({n,x});
            }
            else{
                assert(false);
            }
        }
    }
    cout << ans.size() << "\n";
    for(pair<int,int>nxt: ans){
        cout << nxt.first << " " << nxt.second << "\n";
    }
    return 0;
}