#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=2e5+10;
vector<int>g[mn],w[mn];
int dep[mn],s[mn],o[mn],ct,anc[mn][18];
void dfs(int x,int p){
    anc[x][0]=p;
    o[x]=ct++;
    s[x]=1;
    for(int y:g[x]){
        if(y==p)continue;
        dep[y]=dep[x]+1;
        dfs(y,x);
        s[x]+=s[y];
    }
}
void go(int&a,int b){
    for(int i=0;b;b>>=1,i++)if(b&1)a=anc[a][i];
}
int lca(int a,int b){
    if(dep[a]>dep[b])go(a,dep[a]-dep[b]);
    else go(b,dep[b]-dep[a]);
    for(int i=17;i>=0;i--){
        if(anc[a][i]!=anc[b][i])a=anc[a][i],b=anc[b][i];
    }
    if(a==b)return a;
    return anc[a][0];
}
pii v[mn];
struct comp{
    bool operator()(const pair<pii,int>&a,const pair<pii,int>&b){
        if(a.first.first/v[a.first.second].second!=b.first.first/v[b.first.second].second)return a.first.first/v[a.first.second].second>b.first.first/v[b.first.second].second;
        return a.first.second>b.first.second;
    }
};
int cl[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    for(int i=1;i<18;i++)for(int j=1;j<=n;j++)anc[j][i]=anc[anc[j][i-1]][i-1];
    int q;
    scanf("%d",&q);
    while(q--){
        int k,m;
        scanf("%d%d",&k,&m);
        vector<int>nums,imp;
        for(int i=1;i<=k;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            nums.push_back(a);
            v[i]={a,b};
        }
        for(int i=1;i<=m;i++){
            int a;
            scanf("%d",&a);
            imp.push_back(a);
            nums.push_back(a);
        }
        sort(nums.begin(),nums.end(),[](int a,int b){return o[a]<o[b];});
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int nn=nums.size();
        for(int i=0;i<nn-1;i++)nums.push_back(lca(nums[i],nums[i+1]));
        sort(nums.begin(),nums.end(),[](int a,int b){return o[a]<o[b];});
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        for(int x:nums)g[x].clear(),w[x].clear();
        stack<int>s;
        s.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            while(lca(s.top(),nums[i])!=s.top())s.pop();
            g[s.top()].push_back(nums[i]),g[nums[i]].push_back(s.top());
            w[s.top()].push_back(dep[nums[i]]-dep[s.top()]),w[nums[i]].push_back(dep[nums[i]]-dep[s.top()]);
            s.push(nums[i]);
        }
        priority_queue<pair<pii,int>,vector<pair<pii,int>>,comp>pq;
        for(int i=1;i<=k;i++)pq.push({{v[i].second-1,i},v[i].first});
        for(int x:nums)cl[x]=-1;
        while(pq.size()){
            int d=pq.top().first.first,id=pq.top().first.second,x=pq.top().second;
            pq.pop();
            if(cl[x]!=-1)continue;
            cl[x]=id;
            for(int i=0;i<g[x].size();i++){
                //printf("%d %d\n\n",g[x].size(),w[x].size());
                int y=g[x][i],ww=w[x][i];
                pq.push({{d+ww,id},y});
            }
        }
        for(int x:imp)printf("%d ",cl[x]);
        printf("\n");
    }
}