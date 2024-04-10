#include<bits/stdc++.h>
using namespace std;
long long flow[55][55];
vector<pair<int,long long>> pol[55];
int par[55];
double stale[55][55];
queue<int> q;
void pre(int a)
{
    for(int x=0;x<=a;x++)
    {
        par[x]=-1;
        pol[x].resize(0);
    }
    par[1]=0;
}
long long check(int a,int b)
{
    for(auto x:pol[a])
        if(x.first==b)
            return x.second;
}
void change(int a,int b,long long c)
{
    flow[a][b]-=c;
    flow[b][a]+=c;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d,e,ile;
    cin>>a>>b>>ile;
    while(b--)
    {
        cin>>c>>d>>e;
        stale[c][d]=e;
    }
    double pocz=0,kon=1e9,sr,t=100;
    while(t--)
    {
        sr=(pocz+kon)/2;
        for(int x=1;x<=a;x++)
            for(int y=1;y<=a;y++)
                flow[x][y]=stale[x][y]/sr;
        long long max_flow=0;
        while(0==0)
        {
            pre(a);
            for(int x=1;x<=a;x++)
                for(int y=1;y<=a;y++)
                    if(flow[x][y]!=0)
                        pol[x].push_back(make_pair(y,flow[x][y]));
            q.push(1);
            while(q.empty()==false)
            {
                for(auto x:pol[q.front()])
                    if(par[x.first]==-1)
                    {
                        par[x.first]=q.front();
                        q.push(x.first);
                    }
                q.pop();
            }
            if(par[a]==-1)
                break;
            int pom=a;
            long long mini=1e9+7;
            while(pom!=1)
            {
                mini=min(mini,check(par[pom],pom));
                pom=par[pom];
            }
            pom=a;
            max_flow+=mini;
            while(pom!=1)
            {
                change(par[pom],pom,mini);
                pom=par[pom];
            }
        }
        if(max_flow>=ile)
            pocz=sr;
        else
            kon=sr;
    }
    cout.precision(15);
    cout<<pocz*ile;
	return 0;
}