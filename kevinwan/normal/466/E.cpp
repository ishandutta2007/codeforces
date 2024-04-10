#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e5+10;
vector<int>g[mn];
vector<int>ed;
vector<vector<pii>>qu;
vector<vector<pii>>mp;
int ans[mn];
bool u[mn];
int o[mn],s[mn],ct;
void dfs(int x){
    o[x]=ct++,s[x]=1;
    for(int y:g[x]){
        dfs(y);
        s[x]+=s[y];
    }
}
int p[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    ed.push_back(0),qu.push_back({}),mp.push_back({});
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d",&a);
        if(a==1){
            scanf("%d%d",&a,&b);
            g[b].push_back(a);
            u[a]=1;
            mp[mp.size()-1].push_back({a,b});
        }
        else if(a==2){
            scanf("%d",&a);
            ed.push_back(a),qu.push_back({}),mp.push_back({});
        }
        else{
            scanf("%d%d",&a,&b);
            qu[b].push_back({a,i});
        }
    }
    for(int i=1;i<=n;i++)if(!u[i])g[0].push_back(i);
    dfs(0);
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=0;i<ed.size();i++){
        for(pii el:qu[i]){
            int x=el.first;
            if(o[x]<=o[ed[i]]&&o[ed[i]]<o[x]+s[x]&&f(x)==f(ed[i]))ans[el.second]=1;
            else ans[el.second]=0;
        }
        for(pii el:mp[i]){
            p[f(el.first)]=f(el.second);
        }
    }
    for(int i=0;i<m;i++){
        if(ans[i]==0)printf("NO\n");
        else if(ans[i]==1)printf("YES\n");
    }
}