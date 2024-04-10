#include<bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
const int MOD=1000000007,N=100000;
vector<int>conn[N+5];
vector<int>deg;
bool vi[N+5];
int n,m;
bool cmp(int a,int b){return a>b;}
int idk(int now){
    vi[now]=true;
    int a=1;
    int ahh;
    for(auto x:conn[now]){
        if(!vi[x]){
            ahh=idk(x);
            deg.pb(ahh*(n-ahh));
            a+=ahh;
        }
    }
    return a;
}
void solve(){
    cin>>n;
    int t,tt;
    deg.clear();
    for(int i=0;i<=n;i++)conn[i].clear();
    for(int i=0;i<=n;i++)vi[i]=false;
    for(int i=1;i<n;i++){
        cin>>t>>tt;
        conn[t].pb(tt);
        conn[tt].pb(t);
    }
    cin>>m;
    int p[m+n+5];
    for(int i=0;i<m;i++)cin>>p[i];
    sort(p,p+m);
    for(int i=m;i<=m+n;i++)p[i]=1;
    int wei[n+5];
    for(int i=0;i<n-2;i++)wei[i]=p[i];
    wei[n-2]=1;
    bool big=false;
    for(int i=n-2;i<=m+n;i++){
        wei[n-2]*=p[i];
        if(wei[n-2]>=MOD)big=true;
        wei[n-2]%=MOD;
    }
    if(!big)sort(wei,wei+n-1,cmp);
    else{
        swap(wei[0],wei[n-2]);
        sort(wei+1,wei+n-1,cmp);
    }
    idk(1);
    sort(deg.begin(),deg.end(),cmp);
    for(int i=0;i<n-1;i++)deg[i]%=MOD;
    int ans=0;
    for(int i=0;i<n-1;i++){
        //cout<<deg[i]<<" "<<wei[i]<<endl;
        ans+=deg[i]*wei[i]%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
    return;
}
main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}