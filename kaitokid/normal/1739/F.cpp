#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll val[40009];
int ind,t,l,gg,id[40009],trie[40009][15],f[40009];
vector<int>ch[40009];

int nx[40009][15];
int nw()
{
    for(int i=0;i<13;i++)trie[gg][i]=-1;
    id[gg]=-1;
    ch[gg].clear();
    return gg++;

}
void init()
{
    ind=0;
    gg=0;
    nw();
}
void go()
{
    queue<int> q;
    for(int i=0;i<12;i++)
    {
        int &u=trie[0][i];
        if(u!=-1)
        {
            f[u]=0;
            q.push(u);
        }
        else u=0;
    nx[0][i]=u;
    }

   while(!q.empty())
   {
       int u=q.front();
       for(int i=0;i<12;i++)
        if(trie[u][i]!=-1)nx[u][i]=trie[u][i];
       else nx[u][i]=nx[f[u]][i];
       q.pop();
       for(int i=0;i<ch[u].size();i++)
       {
           int v=f[u];
           while(trie[v][ch[u][i]]==-1)v=f[v];
           v=trie[v][ch[u][i]];
           f[trie[u][ch[u][i]]]=v;
           val[trie[u][ch[u][i]]]+=val[v];
           q.push(trie[u][ch[u][i]]);

       }
   }

}
void insert(string s,int v)
{
    int cur=0;
    for(int i=0;i<s.size();i++)
    {
        if(trie[cur][s[i]-'a']==-1){trie[cur][s[i]-'a']=nw();ch[cur].push_back(s[i]-'a');}
        cur=trie[cur][s[i]-'a'];

    }
  val[cur]+=v;


}
int dp[24009][(1<<12)+10];
int hh[24009][(1<<12)+10];
int go(int x,int msk)
{
    if(msk==(1<<12)-1)return val[x];
    if(dp[x][msk]!=-1)return dp[x][msk];
    dp[x][msk]=0;
    for(int i=0;i<12;i++)
        if((msk&(1<<i))==0){ll jj=go(nx[x][i],msk|(1<<i));
        if(jj>=dp[x][msk]){dp[x][msk]=jj;hh[x][msk]=i;}
        }
    dp[x][msk]+=val[x];

    return dp[x][msk];


}
void rn(int x,int msk)
{
    if(msk==(1<<12)-1)return ;
    cout<<char('a'+hh[x][msk]);
    rn(nx[x][hh[x][msk]],msk|(1<<hh[x][msk]));
}
bool vis[13];
int main()
{
 init();
  int n;
  cin>>n;
    for(int i=0;i<n;i++)
    {
        int c;
        string x;
        cin>>c>>x;
        bool bl=true;
        string r="";
        r+=x[0];
        r+=x[1];
        int d=1;
        for(int i=0;i<12;i++)vis[i]=0;
        vis[x[0]-'a']=vis[x[1]-'a']=1;
        for(int i=2;i<x.size();i++)
        {
            int u=r.size();
            if(d+1<u && r[d+1]==x[i]){d++;continue;}
            if(d-1>=0 &&r[d-1]==x[i]){d--;continue;}
            if(d==0){reverse(r.begin(),r.end());d=u-1;}
            if(vis[x[i]-'a']|| d!=(u-1)){bl=false;break;}
            vis[x[i]-'a']=1;
            d++;
            r+=x[i];
        }
        if(!bl)continue;
        insert(r,c);
        reverse(r.begin(),r.end());
        insert(r,c);
    }
    go();
    memset(dp,-1,sizeof dp);
    go(0,0);
    rn(0,0);
    return 0;
}