
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[200009],y[200009];
map<pair<int,int>,pair<int,int> >ans;
int d1[4]={-1,1,0,0};
int d2[4]={0,0,-1,1};
int main()
{
    int n;
    scanf("%d",&n);
    set<pair<int,int> >st,vis;
    for(int i=0;i<n;i++)
    {
        //cin>>x[i]>>y[i];
        scanf("%d%d",&x[i],&y[i]);
        st.insert({x[i],y[i]});
        vis.insert({x[i],y[i]});
    }
    queue<pair<int,int> >q;
    for(int i=0;i<n;i++)
    {

        for(int w=0;w<4;w++){
                int u=d1[w],v=d2[w];
         if(st.find({x[i]+u,y[i]+v})==st.end())
            {ans[{x[i],y[i]}]={x[i]+u,y[i]+v};
            q.push({x[i],y[i]});
            vis.erase({x[i],y[i]});
        }
        }
    }


    while(!q.empty())
    {
        int r=q.front().first,z=q.front().second;
        q.pop();

        for(int w=0;w<4;w++){
               int  u=d1[w],v=d2[w];
        if(vis.find({r+u,z+v})!=vis.end())
        {
            q.push({r+u,z+v});
            ans[{r+u,z+v}]=ans[{r,z}];
            vis.erase({r+u,z+v});
        }
        }

    }
    for(int i=0;i<n;i++)
        printf("%d %d\n",ans[{x[i],y[i]}].first,ans[{x[i],y[i]}].second);
    return 0;
}