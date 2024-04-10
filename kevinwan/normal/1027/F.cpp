#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=2e6+10;
const ll mod=1e9+7;
int a[mn],b[mn];
int lim,num,nume;
bool vis[mn];
vector<int>g[mn];
void dfs(int x,int p){
    vis[x]=1;
    num++;
    nume+=g[x].size();
    bool don=0;
    for(int y:g[x])if(y!=p){
        if(y>lim)nume++;
        if(!vis[y]&&y<=lim)dfs(y,x);
    }
}
int n;
bool check(int x){
    lim=x;
    memset(vis,0,sizeof(vis));
    int tot=0;
    for(int i=0;i<=lim;i++)if(!vis[i]){
        num=nume=0;
        dfs(i,-1);
        nume/=2;
        tot+=nume;
        if(nume>num)return 0;
    }
    return tot==n;
}
int main() {
    scanf("%d",&n);
    vector<int>nums;
    for(int i=0;i<n;i++)scanf("%d%d",a+i,b+i),nums.push_back(a[i]),nums.push_back(b[i]);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for(int i=0;i<n;i++)a[i]=lower_bound(nums.begin(),nums.end(),a[i])-nums.begin(),b[i]=lower_bound(nums.begin(),nums.end(),b[i])-nums.begin(),g[a[i]].push_back(b[i]),g[b[i]].push_back(a[i]);

    int cur=-1;
    for(int i=1<<20;i;i>>=1){
        if(cur+i>=nums.size())continue;
        if(!check(cur+i))cur+=i;
    }
    if(cur+1>=nums.size())printf("-1");
    else printf("%d",nums[cur+1]);
}