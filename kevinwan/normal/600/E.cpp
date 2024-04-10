#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e5+10;
int c[mn],s[mn];
vector<int> g[mn];
map<int,int> *m[mn];
int num[mn];
ll ans[mn];
void dfs(int x,int p){
    s[x]=1;
    int bes=0;
    for(int y:g[x]){
        if(y==p)continue;
        dfs(y,x);
        s[x]+=s[y];
        if(s[y]>s[bes])bes=y;
    }
    num[x]=num[bes];
    m[x]=m[bes];
    ans[x]=ans[bes];
    if(s[x]==1)m[x]=new map<int,int>();
    for(int y:g[x]){
        if(y==p||y==bes)continue;
        for(pii th:(*m[y])){
            int ne=((*m[x])[th.first]+=th.second);
            if(ne>num[x])ans[x]=th.first,num[x]=ne;
            else if(ne==num[x])ans[x]+=th.first;
        }
    }
    int ne=((*m[x])[c[x]]+=1);
    if(ne>num[x])ans[x]=c[x],num[x]=ne;
    else if(ne==num[x])ans[x]+=c[x];
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i,a,b;
    cin>>n;
    for(i=1;i<=n;i++)cin>>c[i];
    for(i=0;i<n-1;i++)cin>>a>>b,g[a].push_back(b),g[b].push_back(a);
  dfs(1,0);
    for(i=1;i<=n;i++)printf("%lld ",ans[i]);
}