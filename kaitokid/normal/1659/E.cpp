#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int x[100009],y[100009],w[100009];
int pr[35][100009];
int g[35][100009];
vector<pair<int,int> >ed[100009];
void go(int x,int p,int b)
{
    if(pr[b][x]!=0)return;
    pr[b][x]=p;
    for(int i=0;i<ed[x].size();i++)
        if(ed[x][i].second&(1<<b)){go(ed[x][i].first,p,b);g[b][p]&=ed[x][i].second;}
}
bool bl[34][100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<30;i++)
        for(int j=0;j<=n;j++)g[i][j]=(1<<30)-1;
    for(int i=0;i<m;i++)
    {
        cin>>x[i]>>y[i]>>w[i];
        ed[x[i]].push_back({y[i],w[i]});
        ed[y[i]].push_back({x[i],w[i]});

    }
    for(int b=0;b<30;b++)
        for(int i=1;i<=n;i++)
            if(pr[b][i]==0)go(i,i,b);

    for(int i=0;i<m;i++)
    {
        for(int j=1;j<30;j++)
        {
            if((g[j][pr[j][x[i]]]&w[i])==0)bl[j][pr[j][x[i]]]=true;
            if((g[j][pr[j][y[i]]]&w[i])==0)bl[j][pr[j][y[i]]]=true;

        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        bool z=false;
        for(int i=0;i<30;i++)if(pr[i][u]==pr[i][v]){z=true;break;}
        if(z){cout<<0<<endl;continue;}

        for(int i=1;i<30;i++)if(bl[i][pr[i][u]]){z=true;break;}
        if(z)cout<<1<<endl;
        else cout<<2<<endl;
    }

    return 0;
}