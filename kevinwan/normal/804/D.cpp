#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef unsigned long long ll;
typedef pair<ll,ll>pll;
const int mn=1e5+10;
const int sz=350;
vector<int>g[mn];
int cc[mn],down[mn][2],up[mn],dis[mn],dia[mn];
vector<int>pwn[mn];
vector<ll>pre[mn];
int ct=1;
void dfs1(int x,int p){
    cc[x]=ct;
    for(int y:g[x])if(y!=p){
        dfs1(y,x);
        if(down[y][0]+1>down[x][0])down[x][1]=down[x][0],down[x][0]=down[y][0]+1;
        else if(down[y][0]+1>down[x][1])down[x][1]=down[y][0]+1;
    }
}
void dfs2(int x,int p){
    dis[x]=max(down[x][0],up[x]);
    for(int y:g[x])if(y!=p){
        up[y]=max(up[x]+1,((down[y][0]+1==down[x][0])?down[x][1]:down[x][0])+1);
        dfs2(y,x);
    }
}
map<pii,double>hail;
int main(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)if(!cc[i])dfs1(i,0),dfs2(i,0),ct++;
    for(int i=1;i<=n;i++)pwn[cc[i]].push_back(dis[i]),dia[cc[i]]=max(dia[cc[i]],dis[i]);
    for(int i=1;i<ct;i++)sort(pwn[i].begin(),pwn[i].end());
    for(int i=1;i<ct;i++){
        pre[i].resize(pwn[i].size());
        pre[i][0]=pwn[i][0];
        for(int j=1;j<pwn[i].size();j++)pre[i][j]=pre[i][j-1]+pwn[i][j];
        dia[i]--;
    }
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        a=cc[a],b=cc[b];
        if(a==b){printf("-1\n");continue;}
        if(pwn[a].size()<pwn[b].size())swap(a,b);
        if(hail.find({a,b})!=hail.end()){printf("%.20lf\n",hail[{a,b}]);continue;}
        ll ans=0,thres=max(dia[a],dia[b]);
        for(int x:pwn[b]){
            int ind=lower_bound(pwn[a].begin(),pwn[a].end(),(int)thres-x)-pwn[a].begin();
            ans+=pre[a].back()-(ind?pre[a][ind-1]:0)+thres*ind+1LL*x*(pre[a].size()-ind);
        }
        printf("%.20lf\n",hail[{a,b}]=1.*ans/pwn[a].size()/pwn[b].size()+1);
    }
}