#include <bits/stdc++.h>
using namespace std;
const int mn=1e5+10;
const int mv=2e6+10;
vector<int>g[mn];
vector<int>l[mv];
bitset<mv>pr;
int num[mv];
vector<int>v[mn];
int a[mn],par[mn],dep[mn];
void dfs1(int x,int p){
    par[x]=p;
    v[x].resize(l[a[x]].size());
    for(int i=0;i<v[x].size();i++)v[x][i]=num[l[a[x]][i]];
    for(int i=0;i<v[x].size();i++)num[l[a[x]][i]]=x;
    for(int y:g[x]){
        if(y==p)continue;
        dep[y]=dep[x]+1;
        dfs1(y,x);
    }
    for(int i=0;i<v[x].size();i++)num[l[a[x]][i]]=v[x][i];
}
int r;
void dfs2(int x,int p){
    if(x!=r)for(int i=0,j=0;i<l[a[x]].size();i++){
        while(j<l[a[r]].size()&&l[a[r]][j]<l[a[x]][i])j++;
        if(j==l[a[r]].size())break;
        if(l[a[r]][j]==l[a[x]][i]&&v[x][i]==r)v[x][i]=v[r][j];
    }
    for(int y:g[x]){
        if(y==p)continue;
        dfs2(y,x);
    }
}
void dfs3(int x,int p){
    if(x!=r)for(int i=0,j=0;i<l[a[x]].size();i++){
        while(j<l[a[r]].size()&&l[a[r]][j]<l[a[x]][i])j++;
        if(j==l[a[r]].size())break;
        if(l[a[r]][j]==l[a[x]][i]&&dep[v[x][i]]<dep[r])v[x][i]=r;
    }
    for(int y:g[x]){
        if(y==p)continue;
        dfs3(y,x);
    }
}
int main(){
    int n,q;
    dep[0]=-1;
    pr.set();
    pr[0]=pr[1]=0;
    for(int i=2;i*i<mv;i++)if(pr[i])for(int j=i*i;j<mv;j+=i)pr[j]=0;
    for(int i=2;i<mv;i++)if(pr[i])for(int j=i;j<mv;j+=i)l[j].push_back(i);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1,0);
    while(q--){
        int b,c;
        scanf("%d",&b);
        if(b==1){
            int ans=-1;
            scanf("%d",&b);
            for(int x:v[b])if(x){
                if(ans==-1||dep[ans]<dep[x])ans=x;
            }
            printf("%d\n",ans);
        }
        else{
            scanf("%d%d",&b,&c);
            r=b;
            dfs2(b,par[b]);
            a[b]=c;
            v[b].assign(l[a[b]].size(),0);
            for(int x=par[b];x;x=par[x]){
                for(int i=0,j=0;i<v[b].size();i++){
                    while(j<l[a[x]].size()&&l[a[x]][j]<l[a[b]][i])j++;
                    if(j==l[a[x]].size())break;
                    if(l[a[x]][j]==l[a[b]][i]&&!v[b][i])v[b][i]=x;
                }
            }
            dfs3(b,par[b]);
        }
    }
}