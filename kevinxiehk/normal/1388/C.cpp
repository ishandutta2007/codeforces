#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
const int N=100005;
int cnt[N+5];
int happ[N+5];
int sad[N+5];
bool vi[N+5];
int tsad[N+5];
bool poss=true;
int pass[N+5];
vector<int>conn[N+5];
void bfs(int curr){
    vi[curr]=true;
    for(auto x:conn[curr]){
        if(!vi[x]){
            bfs(x);
            pass[curr]+=pass[x];
        }
    }
    return;
}
void bfs2(int curr){
    vi[curr]=true;
    if((pass[curr]-happ[curr])%2==1){poss=false;return;}
    int t=(pass[curr]-happ[curr])/2;
    if(sad[curr]>t){poss=false;return;}
    if(t>pass[curr]){poss=false;return;}
    if(sad[curr]>pass[curr]){poss=false;return;}
    sad[curr]=t;
    for(auto x:conn[curr]){
        if(!vi[x]){
            sad[x]=sad[curr]-(pass[curr]-pass[x]);
            if(sad[x]<0)sad[x]=0;
            bfs2(x);
        }
    }
    return;
}
void bfs3(int curr){
    vi[curr]=true;
    for(auto x:conn[curr]){
        if(!vi[x]){
            tsad[curr]+=sad[x];
            bfs3(x);
        }
    }
    if(tsad[curr]+cnt[curr]<sad[curr]){poss=false;return;}
    return;
}
void solve(){
    int n,m;
    cin>>n>>m;
    poss=true;
    for(int i=1;i<=n;i++)cin>>cnt[i];
    for(int i=1;i<=n;i++)cin>>happ[i];
    for(int i=1;i<=n;i++){
        conn[i].clear();
        pass[i]=cnt[i];
        tsad[i]=0;
        sad[i]=0;
    }
    int t,tt;
    for(int i=1;i<n;i++){
        cin>>t>>tt;
        conn[t].pb(tt);
        conn[tt].pb(t);
    }
    for(int i=1;i<=n;i++)vi[i]=false;
    bfs(1);
    for(int i=1;i<=n;i++)vi[i]=false;
    //for(int i=1;i<=n;i++)cout<<pass[i]<<" ";
    //cout<<endl;
    bfs2(1);
    //for(int i=1;i<=n;i++)cout<<sad[i]<<" ";
    //cout<<endl;
    for(int i=1;i<=n;i++)vi[i]=false;
    bfs3(1);
    //for(int i=1;i<=n;i++)cout<<tsad[i]<<" ";
    //cout<<endl;
    if(poss)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}