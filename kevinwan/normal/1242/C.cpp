#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=2e5+10;
ll n[15],ans[15][2];
vector<ll> a[15];
ll k;
ll sum[15],tar;
pii to[15][5000];
bool vis[15][5000],ins[15][5000];
map<ll,pii>m;
vector<pii>cyc;
ll msk=0;
vector<pii> op[1<<15];
pii st={-1,-1};
bool dfs(int x,int y){
    bool b=0;
    vis[x][y]=ins[x][y]=1;
    if(to[x][y].first!=-1) {
        if (!vis[to[x][y].first][to[x][y].second])b = dfs(to[x][y].first, to[x][y].second);
        else if (ins[to[x][y].first][to[x][y].second])b = 1, cyc.clear(), msk = 0, st = to[x][y];
        if (b && st.first != -1) {
            cyc.push_back({x, y});
            msk |= 1 << x;
        }
        if (make_pair(x, y) == st) {
            st = {-1, -1};
            if(cyc.size()==__builtin_popcount(msk))op[msk] = cyc;
        }
    }
    ins[x][y]=0;
    return b;
}
int dp[1<<15];
vector<int>u[1<<15];
void hail(vector<pii>v){
    reverse(v.begin(),v.end());
    v.push_back(v[0]);
    for(int i=1;i<v.size();i++){
        ans[v[i].first][0]=v[i].second,ans[v[i].first][1]=v[i-1].first;
    }
}
int main(){
    scanf("%lld",&k);
    u[0].push_back(0);
    for(int i=1;i<1<<k;i++){
        int l=i&-i;
        u[i]=u[i-l];
        for(int x:u[i-l])u[i].push_back(x+l);
    }
    ll tot=0;
    for(int i=0;i<k;i++){
        scanf("%d",n+i);
        int x;
        for(int j=0;j<n[i];j++)scanf("%d",&x),a[i].push_back(x),tot+=x,sum[i]+=x,m[x]={i,j};
    }
    tar=tot/k;
    if(tar*k!=tot){
        printf("No");
        return 0;
    }
    memset(ans,-1,sizeof(ans));
    memset(to,-1,sizeof(to));
    for(int i=0;i<k;i++){
        for(int j=0;j<n[i];j++){
            ll x=tar-(sum[i]-a[i][j]);
            if(m.count(x))to[i][j]=m[x];
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n[i];j++){
            if(!vis[i][j])dfs(i,j);
        }
    }
    memset(dp,-1,sizeof(dp));
    dp[0]=0x3f3f3f3f;
    for(int i=1;i<1<<k;i++){
        for(int j:u[i]){
            if(!op[j].size())continue;
            if(dp[i-j]==-1)continue;
            dp[i]=j;
        }
    }
    if(dp[(1<<k)-1]==-1){
        printf("No");
        return 0;
    }
    for(int i=(1<<k)-1;i;i-=dp[i]){
        hail(op[dp[i]]);
    }
    printf("Yes\n");
    for(int i=0;i<k;i++){
        printf("%lld %lld\n",a[i][ans[i][0]],ans[i][1]+1);
    }
}