#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

struct dancer
{
    int g,p,t,id;
};

struct Pos
{
    int x,y;
}ans[MAXN];

bool cmp(const dancer &a,const dancer &b)
{
    return a.p<b.p;
}

int main()
{
    #ifdef KeyID
        freopen("read.txt","r",stdin);
    #endif
    int n,w,h;
    scanf("%d%d%d",&n,&w,&h);
    map <int,vector <dancer>> ms;
    for (int i=0;i<n;i++)
    {
        int g,p,t;
        scanf("%d%d%d",&g,&p,&t);
        ms[t-p].push_back({g,p,t,i});
    }
    for (const auto &v:ms)
    {
        vector <dancer> d[2];
        for (const auto &b:v.second)
            d[b.g-1].push_back(b);
        for (int i=0;i<2;i++)
            sort(d[i].begin(),d[i].end(),cmp);
        for (int i=0;i<d[0].size();i++)
            if (d[0].size()-i-1>=d[1].size())
                ans[d[0][i].id]={d[0][i+d[1].size()].p,h};
            else
                ans[d[0][i].id]={w,d[1][d[0].size()-i-1].p};
        for (int i=0;i<d[1].size();i++)
            if (d[1].size()-i-1>=d[0].size())
                ans[d[1][i].id]={w,d[1][i+d[0].size()].p};
            else
                ans[d[1][i].id]={d[0][d[1].size()-i-1].p,h};
    }
    for (int i=0;i<n;i++)
        printf("%d %d\n",ans[i].x,ans[i].y);
    return 0;
}