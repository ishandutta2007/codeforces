#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=5e5+10;
int o[mn],s[mn],v[mn],d[mn];
int cnt=1;
vector<int> g[mn],p[mn],l[mn];
void dfs(int x){
    s[x]=1;
    o[x]=cnt++;
    l[d[x]].push_back(o[x]);
    p[d[x]].push_back(v[x]);
    for(int y:g[x]){
        d[y]=d[x]+1;
        dfs(y);
        s[x]+=s[y];
    }
}
int bs(int d,int v){
    int cur=0;
    for(int i=1<<19;i;i>>=1){
        if(cur+i>=l[d].size())continue;
        if(l[d][cur+i]<=v)cur+=i;
    }
    return cur;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    string st;
    int n,q,i,j,x;
    cin>>n>>q;
    for(i=2;i<=n;i++){
        cin>>x;
        g[x].push_back(i);
    }
    d[1]=1;
    cin>>st;
    for(i=0;i<n;i++){
        v[i+1]=1<<(st[i]-'a');
    }
    for(i=1;i<=n;i++)p[i].push_back(0),l[i].push_back(0);
    dfs(1);
    for(i=1;i<=n;i++){
        for(j=1;j<p[i].size();j++)p[i][j]^=p[i][j-1];
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        int ql,qr;
        ql=bs(b,o[a]-1),qr=bs(b,o[a]+s[a]-1);
        int res=p[b][qr]^p[b][ql];
        if(res==(res&-res))printf("Yes\n");
        else printf("No\n");
    }
}