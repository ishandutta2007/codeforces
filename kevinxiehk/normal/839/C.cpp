#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
bool vi[100005];
long double ans=0;
vector<int>path[100005];
void dfs(int now,long double probb,long double dist){
    vi[now]=true;
    if(now!=1&&path[now].size()==1){ans+=dist*probb;return;}
    long double aaa=path[now].size();
    if(now!=1)aaa--;
    for(auto x:path[now]){
        if(!vi[x]){
            dfs(x,probb/aaa,dist+1);
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)vi[i]=false;
    int t,tt;
    for(int i=1;i<n;i++){
        cin>>t>>tt;
        path[t].pb(tt);
        path[tt].pb(t);
    }
    dfs(1,1.00000000000000,0.0000000000000);
    cout<<fixed<<setprecision(20)<<ans<<endl;
    return 0;
}