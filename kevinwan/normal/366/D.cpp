#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e3+10;
vector<int>g[mn],l[mn],r[mn];
map<int,int>comp;
int bes[mn][6*mn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int>nums;
    for(int i=0;i<m;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        g[a].push_back(b);
        g[b].push_back(a);
        l[a].push_back(c);
        l[b].push_back(c);
        r[a].push_back(++d);
        r[b].push_back(d);
        nums.push_back(c);
        nums.push_back(d);
    }
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for(int i=0;i<nums.size();i++)comp[nums[i]]=i;
    for(int i=1;i<=n;i++)for(int j=0;j<g[i].size();j++)l[i][j]=comp[l[i][j]],r[i][j]=comp[r[i][j]];
    memset(bes,-1,sizeof(bes));
    priority_queue<pair<int,pii>>pq;
    pq.push({0x3f3f3f3f,{1,0}});
    while(pq.size()){
        int v=pq.top().first,x=pq.top().second.first,z=pq.top().second.second;
        pq.pop();
        if(bes[x][z]!=-1)continue;
        bes[x][z]=v;
        for(int i=0;i<g[x].size();i++){
            int y=g[x][i],lv=l[x][i],rv=r[x][i];
            int nv=min(v,rv),nz=max(z,lv);
            if(nz>=nv)continue;
            pq.push({min(v,rv),{y,max(z,lv)}});
        }
    }
    int ans=0;
    for(int i=0;i<nums.size();i++)if(bes[n][i]!=-1)ans=max(ans,nums[bes[n][i]]-nums[i]);
    if(ans==0)printf("Nice work, Dima!");
    else printf("%d",ans);
}