#include<bits/stdc++.h>
using namespace std;
#define int long long
bool odw[1005][1005];
int change[1005][1005];
bool init[1005][1005];
queue<pair<pair<int,int> , int>> q;
vector<pair<int,int>> pol;
void lul()
{
    pol.push_back(make_pair(-1,0));
    pol.push_back(make_pair(1,0));
    pol.push_back(make_pair(0,1));
    pol.push_back(make_pair(0,-1));
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	lul();
    int a,b,t;
    cin>>a>>b>>t;
    for(int x=0;x<=a+1;x++)
        for(int y=0;y<=b+1;y++)
            odw[x][y]=true;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
        {
            char c;
            cin>>c;
            init[x][y]=(c-'0');
            odw[x][y]=false;
        }
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
        {
            for(auto z:pol)
                if(init[x+z.first][y+z.second]==init[x][y] && x+z.first>0 && x+z.first<=a && y+z.second >0 && y+z.second<=b)
                {
                    q.push(make_pair(make_pair(x,y),1));
                    change[x][y]=1;
                    odw[x][y]=true;
                    break;
                }
        }
    if(q.empty())
    {
        while(t--)
        {
            int c,d,e;
            cin>>c>>d>>e;
            cout<<init[c][d]<<'\n';
        }
        return 0;
    }
    while(!q.empty())
    {
        auto pom=q.front();
        q.pop();
        int c=pom.first.first,d=pom.first.second;
        bool stan=init[c][d];
        if(pom.second==change[c][d])
            stan=(!stan);
        for(auto x:pol)
        {
            if(!odw[c+x.first][d+x.second] && stan==init[c+x.first][d+x.second])
            {
                change[c+x.first][d+x.second]=pom.second+1;
                odw[c+x.first][d+x.second]=true;
                q.push(make_pair(make_pair(c+x.first,d+x.second) , pom.second+1));
            }
        }
        if(pom.second-change[c][d]==0)
            q.push(make_pair(pom.first,pom.second+1));
    }
    while(t--)
    {
        int c,d;
        long long e;
        cin>>c>>d>>e;
        if(e<change[c][d])
            cout<<init[c][d]<<'\n';
        else
        {
            long long pom=e-change[c][d];
            pom%=2;
            pom^=1;
            bool xd=pom;
            cout<<(init[c][d]^xd)<<'\n';
        }
    }
    return 0;
}