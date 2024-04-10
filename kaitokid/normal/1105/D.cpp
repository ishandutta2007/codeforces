#include <bits/stdc++.h>

using namespace std;
int n,m,p,now;
char x;
deque<pair<pair<int,int>,int > >a[11];
int vis[1002][1002];
int fas[11],ans[11];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>p;
    for(int i=1;i<=p;i++)cin>>fas[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        cin>>x;
        if(x=='.')continue;
        now++;
        if(x=='#'){vis[i][j]=-1;continue;}
        vis[i][j]=(x-'0');
        a[x-'0'].push_back(make_pair(make_pair(i,j),0));
    ans[x-'0']++;
    }
int rrr=1;
    while(now<n*m)
    {
        int y=0;
        for(int i=1;i<=p;i++)
        {

            int l=a[i].size();
             if(l==0)y++;
             while(!a[i].empty()&&a[i].front().second<fas[i]*rrr)
            {
                int w=a[i].front().first.first;
                int e=a[i].front().first.second;
                int uiu=a[i].front().second;
                for(int q=w+1;q<=min(n-1,w+1);q++)
                {if(vis[q][e]!=0)break;
                if(uiu+q-w>fas[i]*rrr)break;
                 ans[i]++;a[i].push_back(make_pair(make_pair(q,e),uiu+q-w));vis[q][e]=i;now++;}
            for(int q=w-1;q>=max(0,w-1);q--)if(vis[q][e]!=0||uiu+w-q>fas[i]*rrr)break;else {ans[i]++;
            a[i].push_back(make_pair(make_pair(q,e),uiu+w-q));vis[q][e]=i;now++;}
            for(int q=e+1;q<=min(m-1,e+1);q++)if(vis[w][q]!=0||uiu+q-e>fas[i]*rrr)break;else {ans[i]++;
            a[i].push_back(make_pair(make_pair(w,q),uiu+q-e));vis[w][q]=i;now++;}
            for(int q=e-1;q>=max(0,e-1);q--)if(vis[w][q]!=0||uiu+e-q>fas[i]*rrr)break;else {ans[i]++;
            a[i].push_back(make_pair(make_pair(w,q),e-q+uiu));vis[w][q]=i;now++;}
            a[i].pop_front();
            }
        }

    if(y==p)break;
    rrr++;}
    for(int i=1;i<=p;i++)cout<<ans[i]<<" ";
    return 0;
}