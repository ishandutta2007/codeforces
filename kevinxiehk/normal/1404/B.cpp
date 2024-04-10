#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
void solve(){
    int n,a,b,da,db;
    cin>>n>>a>>b>>da>>db;
    vector<int>conn[n+5];
    int t,tt;
    for(int i=1;i<n;i++){
        cin>>t>>tt;
        conn[t].pb(tt);
        conn[tt].pb(t);
    }
    int dist[n+5];
    for(int i=0;i<=n;i++)dist[i]=9999999;
    queue<pair<int,int>>bfs;
    bfs.push(mp(1,0));
    while(!bfs.empty()){
        if(bfs.front().se>dist[bfs.front().fi])bfs.pop();
        else{
            dist[bfs.front().fi]=bfs.front().se;
            for(auto x:conn[bfs.front().fi]){
                bfs.push(mp(x,bfs.front().se+1));
            }
            bfs.pop();
        }
    }
    int tm=0,im=0;
    for(int i=1;i<=n;i++){
        if(dist[i]>tm){
            tm=dist[i];
            im=i;
        }
    }
    bfs.push(mp(im,0));
    for(int i=0;i<=n;i++)dist[i]=9999999;
    while(!bfs.empty()){
        if(bfs.front().se>dist[bfs.front().fi])bfs.pop();
        else{
            dist[bfs.front().fi]=bfs.front().se;
            for(auto x:conn[bfs.front().fi]){
                bfs.push(mp(x,bfs.front().se+1));
            }
            bfs.pop();
        }
    }
    int m=0;
    for(int i=1;i<=n;i++)m=max(m,dist[i]);
    bfs.push(mp(a,0));
    for(int i=0;i<=n;i++)dist[i]=9999999;
    while(!bfs.empty()){
        if(bfs.front().se>dist[bfs.front().fi])bfs.pop();
        else{
            dist[bfs.front().fi]=bfs.front().se;
            for(auto x:conn[bfs.front().fi]){
                bfs.push(mp(x,bfs.front().se+1));
            }
            bfs.pop();
        }
    }
    //cout<<m<<endl;
    //cout<<dist[b]<<endl;
    if(dist[b]<=da){cout<<"Alice"<<endl;return;}
    if(min(m,db)<2*da+1){cout<<"Alice"<<endl;return;}
    cout<<"Bob"<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;

    cin>>t;
    
    while(t--)solve();
    return 0;
}