#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
map<string,int>mp;
int cot=0,ans=0,n,m,cnt=0,a[45],anss[45],vis[45];
bool v[45][45];
void dfs(int x,int pos)
{
    for(int i=x+1; i<=cot; i++)
    {
        if(pos+anss[i]<=ans) return;
        bool flag=true;
        if(!v[x][i]) continue;
        for(int j=0; j<pos; j++) if(!v[i][vis[j]]) {
                flag=false;
                break;
            }
        if(flag)
        {
            vis[pos]=i;
            dfs(i,pos+1);
        }
    }
    ans=max(ans,pos);
}
int main()
{
    memset(v,true,sizeof(v));
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        int opt;
        scanf("%d",&opt);
        if(opt==1)
        {
            for(int i=0; i<cnt; i++)
                for(int j=i+1; j<cnt; j++) v[a[i]][a[j]]=v[a[j]][a[i]]=false;
            cnt=0;
        }
        else
        {
            string s;
            cin>>s;
            if(!mp[s]) mp[s]=++cot;
            a[cnt++]=mp[s];
        }
    }
    for(int i=0; i<cnt; i++)
        for(int j=i+1; j<cnt; j++) v[a[i]][a[j]]=v[a[j]][a[i]]=false;
    for(int i=cot; i>0; i--)
    {
        vis[0]=i;
        dfs(i,1);
        anss[i]=ans;
    }
    cout<<ans<<endl;
}