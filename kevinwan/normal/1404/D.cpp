#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
int p[mn],lv[mn];
vector<int>g[mn];
int s[mn];
bool vis[mn],st[mn];
ll sum=0;
int n;
void dfs(int x){
    vis[x]=st[x]=s[x]=1;
    for(int y:g[x])if(st[y])st[x]=0;
    for(int y:g[x])if(!vis[y]){
            st[y]=st[x]^1;
            dfs(y);
            s[x]+=s[y];
        }
    if(st[x])sum+=x,sum%=2*n;
}
void dfs2(int x){
    vis[x]=1;
    st[x]^=1;
    for(int y:g[x])if(!vis[y]){
            dfs2(y);
        }
}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    //cin.tie(0);
    //cin.sync_with_stdio(0);
    cin>>n;
    if(n&1){
        cout<<"Second"<<endl;
        for(int i=1;i<=2*n;i++)cin>>p[i];
        for(int i=1;i<=2*n;i++){
            if(!lv[p[i]])lv[p[i]]=i;
            else{
                int l=lv[p[i]];
                if(l!=i-n){
                    g[l].push_back(i);
                    g[i].push_back(l);
                }
            }
        }
        for(int i=1;i<=n;i++)g[i].push_back(i+n),g[i+n].push_back(i);
        int pwn=0;
        for(int i=1;i<=2*n;i++)if(!vis[i]){
                dfs(i);
                if(s[i]%4==2)pwn=i;
            }
        memset(vis,0,sizeof(vis));
        if(sum){
            dfs2(pwn);
        }
        for(int i=1;i<=2*n;i++)if(st[i])printf("%d ",i);
        cout<<endl;
        int r;
        cin>>r;
    }
    cout<<"First"<<endl;
    int mo=1<<__builtin_ctz(n);
    int cur=1;
    for(int i=1;i<=2*n;i+=2*mo){
        for(int j=i;j<i+mo;j++){
            p[j]=p[j+mo]=cur++;
        }
    }
    for(int i=1;i<=2*n;i++)printf("%d ",p[i]);
    cout<<endl;
    int r;
    cin>>r;
}