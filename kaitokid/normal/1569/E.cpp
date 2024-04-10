#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll p,k,h;
ll d[1009];
vector<vector<int> >ways;
bool ans;
vector<vector<int> > go(int l,int r,int d,int kk)
{
    vector< vector<int> > rr;
    if(l==r)
    {
        vector<int> g;
        g.push_back(d);
        rr.push_back(g);
        return rr;
    }
    int mid=(l+r)/2;
    vector<vector<int> >z=go(l,mid,d+(1<<kk),kk+1);
    //vector<vector<int> >z2=go(mid+1,r,d+1);
    for(int i=0;i<z.size();i++)
    for(int j=0;j<z.size();j++)
    {
        vector<int> w=z[i];
        for(int q=0;q<z[j].size();q++)
            if(z[j][q]==d+(1<<kk))w.push_back(d);
        else w.push_back(z[j][q]);
        rr.push_back(w);
        w.clear();
        for(int q=0;q<z[i].size();q++)
            if(z[i][q]==d+(1<<kk))w.push_back(d);
            else w.push_back(z[i][q]);
        for(int q=0;q<z[j].size();q++)w.push_back(z[j][q]);
        rr.push_back(w);

    }
    return rr;
}

map<ll,vector<int> > mp[2][2];
void prn(int x,int y ,int gg)
{
    for(int i=0;i<mp[x][y][gg].size();i++)cout<<mp[x][y][gg][i]<<" ";
}
void cal(int x)
{
    ll res=0;
    for(int i=0;i<ways[x].size();i++)
    {
        res+=d[ways[x][i]]*(i+1);
        res%=mod;
    }
    mp[0][0][res]=ways[x];
    if(!mp[1][1][(h-res+mod)%mod].empty())
    {
        prn(0,0,res);
        prn(1,1,(h-res+mod)%mod);
        ans=true;
        return;
    }
    res=0;
    for(int i=0;i<ways[x].size();i++)
    {
        res+=d[ways[x][i]]*(i+((1<<(k-1))+1));
        res%=mod;
    }
    mp[1][0][res]=ways[x];
    if(!mp[0][1][(h-res+mod)%mod].empty())
    {
        prn(0,1,(h-res+mod)%mod);
        prn(1,0,res);
        ans=true;
        return;
    }
    for(int i=0;i<ways[x].size();i++)if(ways[x][i]==2)ways[x][i]=1;
   res=0;
    for(int i=0;i<ways[x].size();i++)
    {
        res+=d[ways[x][i]]*(i+1);
        res%=mod;
    }
    mp[0][1][res]=ways[x];
    if(!mp[1][0][(h-res+mod)%mod].empty())
    {
        prn(0,1,res);
        prn(1,0,(h-res+mod)%mod);
        ans=true;
        return;
    }
    res=0;
    for(int i=0;i<ways[x].size();i++)
    {
        res+=d[ways[x][i]]*(i+((1<<(k-1))+1));
        res%=mod;
    }
    mp[1][1][res]=ways[x];

  if(!mp[0][0][(h-res+mod)%mod].empty())
    {
        prn(0,0,(h-res+mod)%mod);

        prn(1,1,res);
        ans=true;
        return;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 cin>>k>>p>>h;
    d[0]=1;
    for(int i=1;i<1000;i++)d[i]=(d[i-1]*p)%mod;
    ways= go( 1,(1<<(k-1)),2,0);

    for(int i=0;i<ways.size();i++)
    {
        cal(i);
        if(ans)break;
    }
    if(!ans)cout<<-1;
    return 0;
}