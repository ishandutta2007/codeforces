#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

int count[1048576];
int head[200001],nxt[400001],b[400001],k,n,stat[200001],size[200001],mx[200001],full,root;
long long ans[200001];
bool vis[200001];
void push(int s,int t){
    nxt[++k]=head[s];
    head[s]=k;
    b[k]=t;
}
void getroot(int x,int f){
    mx[x]=0;
    size[x]=1;
    for(int i=head[x];i;i=nxt[i])
        if(!vis[b[i]]&&b[i]!=f){
            getroot(b[i],x);
            mx[x]=std::max(mx[x],size[b[i]]);
            size[x]+=size[b[i]];
        }
    mx[x]=std::max(mx[x],full-size[x]);
    if(mx[x]<mx[root])root=x;
}
long long getdis(int x,int f,int stats){
    long long tot=0;
    tot+=count[stats];
    for(int i=0;i<20;i++)tot+=count[stats^(1<<i)];
    size[x]=1;
    for(int i=head[x];i;i=nxt[i])
        if(b[i]!=f&&!vis[b[i]]){
            tot+=getdis(b[i],x,stats^stat[b[i]]);
            size[x]+=size[b[i]];
        }
    ans[x]+=tot;
    return tot;
}
void adddis(int x,int f,int stats,int flag){
    if(flag==1)count[stats]++;
    else count[stats]--;
    for(int i=head[x];i;i=nxt[i])
        if(b[i]!=f&&!vis[b[i]])adddis(b[i],x,stats^stat[b[i]],flag);
}
void solve(int rt){
    vis[rt]=1;
    std::vector<int> vec;
    count[stat[rt]]=1;
    for(int i=head[rt];i;i=nxt[i])
        if(!vis[b[i]]){
            ans[rt]+=getdis(b[i],rt,stat[b[i]]);
            adddis(b[i],rt,stat[b[i]]^stat[rt],1);
            vec.push_back(b[i]);
        }
    ans[rt]++;
    for(int i=0;i<vec.size();i++)adddis(vec[i],rt,stat[vec[i]]^stat[rt],-1);
    count[stat[rt]]=0;
    for(int i=vec.size()-1;i>=0;i--){
        getdis(vec[i],rt,stat[vec[i]]);
        adddis(vec[i],rt,stat[vec[i]]^stat[rt],1);
    }
    for(int i=0;i<vec.size();i++)adddis(vec[i],rt,stat[vec[i]]^stat[rt],-1);
    for(int i=0;i<vec.size();i++){
        full=size[vec[i]];
        mx[root=0]=1000000;
        getroot(vec[i],rt);
        solve(root);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1,s,t;i<n;i++){
        scanf("%d%d",&s,&t);
        push(s,t);
        push(t,s);
    }
    for(int i=1;i<=n;i++){
        stat[i]=getchar();
        while(stat[i]<'a'||stat[i]>'t')stat[i]=getchar();
        stat[i]=1<<(stat[i]-'a');
    }
    full=n;
    mx[root=0]=1000000;
    getroot(1,0);
    solve(root);
    for(int i=1;i<=n;i++)std::cout<<ans[i]<<' ';
}